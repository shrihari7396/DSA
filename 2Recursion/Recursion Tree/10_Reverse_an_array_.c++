#include <bits/stdc++.h>
using namespace std;

void Reverse_array1(int N,int arr[],vector<int>& reversed){

    if(N < 0){
        return;
    }
    reversed.emplace_back(arr[N]);
    Reverse_array1(N-1,arr,reversed);
}

void Reverse_array2(int i, int N,int arr[]){
   if(i >= N/2){
    return;
   }
   swap(arr[i], arr[N-i-1]);
   Reverse_array2(i + 1, N ,arr);
}
int main(void){
    int N;
    cin  >> N;
    int  arr[N-1];

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    cout << "Orignal array : ";
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
// 1
    vector<int>Reversed_array;
    cout << "Reversed array_1 : ";

    Reverse_array1(N-1,arr,Reversed_array);

    for (auto it = Reversed_array.begin(); it != Reversed_array.end(); it++){
        cout << *(it) << " ";
    }
    cout << endl;

//2
    int j = 0;
    Reverse_array2(j, N,arr);
    cout << "reversed array_2 is : ";
    for(int i = 0; i<N; i++){
        cout << arr[i] << " ";
    }
 return 0;
}
