#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main(){
    int n, m; cin >> n >> m;
    int result = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum <= m){
                    result = max(result, sum);
                }
            }
        }
    }
    cout << result;
}