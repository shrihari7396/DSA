#include <bits/stdc++.h>
using namespace std;

class PeekAndNotPeak {
private:
    vector<int> nums;
public:

    void printS(int ind, vector<int>& ds, int s, int sum, int arr[], int n) {
        if(ind == n) {
            if(s==sum) {
                for(auto it : ds) cout << it << " ";
                cout<<endl;
            }
            return;
        }

        ds.emplace_back(arr[ind]);
        s+=arr[ind];
        printS(ind+1, ds, s, sum, arr, n);
        
        // not Pick
        s -= arr[ind];
        ds.pop_back();

        printS(ind+1, ds, s, sum, arr, n);
    }

    bool printSWantOnlyFirstSubsequence(int ind, vector<int>& ds, int s, int sum, int arr[], int n) {
        if(ind == n) {
            if(s==sum) {
                for(auto it : ds) cout << it << " ";
                cout<<endl;
                return true;
            }
            return false;
        }

        ds.emplace_back(arr[ind]);
        s+=arr[ind];
        if(printSWantOnlyFirstSubsequence(ind+1, ds, s, sum, arr, n)) return true;
        
        // not Pick
        s -= arr[ind];
        ds.pop_back();

        if(printSWantOnlyFirstSubsequence(ind+1, ds, s, sum, arr, n)) return true;

        return false;
    }

    int printSWantToCountTheSubsequences(int ind, vector<int>& ds, int s, int sum, int arr[], int n) {
        if(ind == n) {
            if(s==sum) {
                for(auto it : ds) cout << it << " ";
                cout<<endl;
                return 1;
            }
            return 0;
        }

        ds.emplace_back(arr[ind]);
        s+=arr[ind];

        int left = printSWantToCountTheSubsequences(ind+1, ds, s, sum, arr, n);
        
        // not Pick
        s -= arr[ind];
        ds.pop_back();

        int right = printSWantToCountTheSubsequences(ind+1, ds, s, sum, arr, n);

        return left + right;
    }
    
};

int main(int argc, char** argv) {
    int arr[] = {1, 2, 1, 23, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = 14;
    int sum = 3;
    vector<int> ds;
    PeekAndNotPeak *obj = new PeekAndNotPeak();
    int count = obj->printSWantToCountTheSubsequences(0, ds, 0, sum, arr, n);
    cout<<"Count is: " << count << endl;
    return 0;
}