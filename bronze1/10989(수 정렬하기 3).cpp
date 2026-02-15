#include <bits/stdc++.h>
using namespace std;

int arr[10001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while(n--){
        int num; cin >> num;
        arr[num]++;
    }


    for(int i = 1; i <= 10000; i++){
        if(arr[i]){
            while(arr[i]){
                cout << i << "\n";
                arr[i]--;
            }
        }
    }
}