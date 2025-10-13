#include <bits/stdc++.h>
using namespace std;
int arr[8];
int main(){
    for(int i = 0; i < 8; i++){
        cin >> arr[i];
    }
    if(arr[0] == 1){
        for(int i = 1; i <= 7; i++){
            if(arr[i] != i+1){
                cout << "mixed";
                return 0;
            }
        }
        cout << "ascending";
    }
    else if(arr[0] == 8){
        for(int i = 1; i <= 7; i++){
            if(arr[i] != 8-i){
                cout << "mixed";
                return 0;
            }
        }
        cout << "descending";
    }
    else
        cout << "mixed";
}