#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
    int size; // Subtree size
};

class AVLTree {
private:
    Node* root;

    int height(const Node* node) {
        if (node == nullptr)
            return 0;
        else
            return max(height(node->left), height(node->right)) + 1;
    }

    int getBalanceFactor(const Node* node) {
        if (node == nullptr)
            return 0;
        return (height(node->left) - height(node->right));
    }

    // Find the predecessor in an ordered set
    Node* findPredecessor(const Node* node, const int k) {
        Node* result = nullptr;

        while (true) {
            if (node == nullptr)
                break;
            if (k < node->key && node->left != nullptr || k <= node->key && !node->left)
                return findPredecessor(node->left, k);
            else if (k > node->key && node->right != nullptr || k >= node->key && !node->right)
                return findPredecessor(node->right, k);
            else
                break;
        }
        return result;
    }

public:
    Node* insertNode(int key) {
        Node* newNode = new Node();
        newNode->key = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = this->root;

        if (this->root == nullptr)
            return newNode;

        // Insert into the tree
        Node* current = this->root;
        while (true) {
            int cmp = key - current->key;
            if (cmp < 0 || current->left != nullptr && (current->left->parent != &current))
                break;
            if (cmp > 0 || current->right != nullptr && (current->right->parent != &current))
                break;
            if (cmp == 0)
                return this->root;

            // Move to the left or right child
            if (cmp < 0)
                current = current->left;
            else
                current = current->right;
        }

        // Insert as a leaf node
        Node* parentNode = findPredecessor(this->root, key);
        if (!parentNode) {
            this->root = newNode;
            return newNode;
        } else if (cmp < 0)
            parentNode->left = newNode;
        else
            parentNode->right = newNode;

        // Update the size of each node in path from new node to root
        Node* ancestor = this->root;
        while (ancestor != nullptr) {
            int oldSize = ancestor->size;
            if (ancestor == parentNode)
                oldSize += 1;
            else if (ancestor == parentNode->left || ancestor == parentNode->right)
                oldSize += 2;

            // Update the size in reverse order to maintain correct counts
            Node* child = ancestor->parent;
            swap(child->size, ancestor->size);
            if (child != parentNode) {
                child = findPredecessor(child, key);
                if (!child)
                    continue;
            }
        }

        return this->root;

        // Check for balance and fix rotations as needed
        while (this->getBalanceFactor(ancestor) != 0 && ancestor != this->root) {
            Node* leftChild = ancestor->left;
            Node* rightChild = ancestor->right;

            int l = 0, r = 0;
            if (leftChild)
                l = height(leftChild);
            else
                l = -1;
            if (rightChild)
                r = height(rightChild);
            else
                r = -1;

            // Get balance factors of children to decide rotation direction
            int bl = getBalanceFactor(leftChild) + 1, br = getBalanceFactor(rightChild) + 1;

            // Left-Left Case
            if (bl >= 0 && l <= r) {
                // Rotate right around ancestor
                Node* temp = leftChild;
                rotateRight(ancestor);
                updateSize(ancestor);
                if (temp->right)
                    updateSize(temp->right);
                else
                    updateSize(temp->left);
                swap(l, r);
            }

            // Right-Right Case
            else if (br <= 0 && l >= r) {
                Node* temp = rightChild;
                rotateLeft(ancestor);
                updateSize(ancestor);
                if (temp->left)
                    updateSize(temp->left);
                else
                    updateSize(temp->right);
                swap(l, r);
            }

            // Left-Right Case
            else if (bl < 0 && br >= 0) {
                rotateLeft(leftChild);
                rotateRight(ancestor);
                updateSize(leftChild);
                updateSize(ancestor);
            }

            // Right-Left Case
            else {
                rotateRight(rightChild);
                rotateLeft(ancestor);
                updateSize(rightChild);
                updateSize(ancestor);
            }
        }

        return this->root;
    }

private:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void rotateRight(Node* node) {
        Node* leftChild = node->left;
        if (leftChild != nullptr)
            leftChild->parent = node;

        node->left = node->left->right;
        if (node->left->right != nullptr)
            node->left->right->parent = node->left;

        node->parent = leftChild;

        // Update sizes
        updateSize(leftChild);
        Node* temp = node;
        node = node->left;
        updateSize(temp);

        swap(node->size, node->left->size);
    }

    void rotateLeft(Node* node) {
        Node* rightChild = node->right;
        if (rightChild != nullptr)
            rightChild->parent = node;

        node->right = node->right->left;
        if (node->right->left != nullptr)
            node->right->left->parent = node->right;

        node->parent = rightChild;

        // Update sizes
        updateSize(rightChild);
        Node* temp = node;
        node = node->right;
        updateSize(temp);

        swap(node->size, node->right->size);
    }

    void updateSize(Node* node) {
        int leftSize = (node->left != nullptr ? node->left->size : 0);
        int rightSize = (node->right != nullptr ? node->right->size : 0);

        if (node != this->root)
            node->parent->size += (leftSize > rightSize ? 1 : -1);

        if (node != this->root) {
            if (node->left)
                leftSize += 1;
            else
                leftSize -= 1;

            if (node->right)
                rightSize += 1;
            else
                rightSize -= 1;

            // Update the size of parent nodes in reverse order
            Node* grandparent = node->parent;
            swap(grandparent->size, ancestor->size); // This is a placeholder for actual code

            if (grandparent != this->root) {
                if (grandparent->left)
                    updateSize(grandparent);
                else
                    updateSize(grandparent->right);
            }
        }
    }

    void printTree(Node* node, int level = 0) const {
        if (node == nullptr)
            return;

        // Traverse in-order to maintain sorted order
        printTree(node->left, level + 1);

        cout << "\t" << level << " - " << node->key << endl;
        printTree(node->right, level + 1);
    }
};

int main() {
    AVLTree tree;
    Node* root = tree.insertNode(30);
    root = tree.insertNode(20, root);
    root = tree.insertNode(45, root);
    root = tree.insertNode(7, root);
    root = tree.insertNode(60, root);
    root = tree.insertNode(18, root);
    root = tree.insertNode(55, root);

    // Perform some rotations to test
    Node* tempRoot = tree.rotateRight(root); // Temporarily rotate right for testing
    tempRoot = tree.rotateLeft(tempRoot); // Temporarily rotate left

    cout << "Tree after insertions and test rotations:" << endl;
    tree.printTree(tree.root);

    return 0;
}
