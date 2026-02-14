#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    int sum = 1;
    cin >> n >> k;

    for(int i = n; i > n-k; i--){
        sum*=i;
    }
    for(int j = 1; j <= k; j++){
        sum/=j;
    }
    cout << sum;
}