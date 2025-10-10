#include <bits/stdc++.h>
using namespace std;

int arr[42];

int main(){
    int res = 0;
    for(int i = 0; i < 10; i++){
        int tmp;
        cin >> tmp;
        arr[tmp%42]++;
    }
    for(int i = 0; i < 42; i++){
        if(arr[i])
            res++;
    }
    cout << res;
}