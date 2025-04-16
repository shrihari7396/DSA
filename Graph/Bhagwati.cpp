#include <iostream>
using namespace std;

//
// Example 1: Using Multiple Namespaces with Explicit Access
//

// Defining the first namespace
namespace Namespace1 {
    int number = 10;
    void display() {
        cout << "Displaying from Namespace1" << endl;
        cout << "Value of number: " << number << endl;
    }
}

// Defining the second namespace
namespace Namespace2 {
    int number = 20;
    void display() {
        cout << "Displaying from Namespace2" << endl;
        cout << "Value of number: " << number << endl;
    }
}

//
// Example 2: Using 'using namespace' Directive
//

// Defining a third namespace
namespace MyNamespace {
    int value = 100;
    void display() {
        cout << "Value from MyNamespace: " << value << endl;
    }
}

int main() {
    cout << "----- Example 1: Multiple Namespaces -----" << endl;

    // Accessing functions and variables from different namespaces
    Namespace1::display();
    Namespace2::display();

    // Accessing variables from different namespaces
    cout << "Accessing number from Namespace1: " << Namespace1::number << endl;
    cout << "Accessing number from Namespace2: " << Namespace2::number << endl;

    cout << "\n----- Example 2: using namespace Directive -----" << endl;

    // Using the entire namespace to avoid prefixing
    using namespace MyNamespace;

    // Now we can directly access the members of MyNamespace
    display();
    cout << "Accessing value from MyNamespace: " << value << endl;

    return 0;
}
