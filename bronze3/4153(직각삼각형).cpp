#include <bits/stdc++.h>
using namespace std;

int arr[3];

int main(){
    while(1){
        cin >> arr[0] >> arr[1] >> arr[2];
        if(arr[0]+arr[1]+arr[2] == 0) break;
        sort(arr, arr+3);
        if(arr[2]*arr[2] == arr[0]*arr[0] + arr[1]*arr[1])
            cout << "right" << endl;
        else
            cout << "wrong" << endl;        
    }
}