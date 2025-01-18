#include <iostream>
using namespace std;
// This is Brian Kernighan's Algorithm
int main()
{
    int n;
    cin >> n;
    int count = 0;
    while(n)
    {
        n = n & (n-1);
        count ++;
    }
    cout << count << endl;
    return 0;
}