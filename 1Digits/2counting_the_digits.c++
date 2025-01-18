#include <bits/stdc++.h>
using namespace std;
int count_the_digits_in_number(int i){
    int j = 0;
    while(i > 0){
        if(i>= 0){
            j++;
        }
        i = i/10;
    }
    return j;
}

int count(int i){
    int count = log10(i) + 1;
    return count;

}

int main(void){
    int i ;
    cin >> i ;
    cout << count_the_digits_in_number(i) << endl << count(i) << endl;
    return 0;
}