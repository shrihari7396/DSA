#include <bits/stdc++.h>
using namespace std;
int reversing_a_number(int i){
    int reverse_num = 0;
    while (i > 0){
        reverse_num = (reverse_num)*10 + i % 10;
        i = i /10;
    }
    return reverse_num;
}
int main(void){
    int i;
    cin >> i;
    cout << reversing_a_number(i);
    return 0;
}