#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    int sum = 1;
    int i = 1;
    while(sum < n){
        sum += 6 * i;
        i++;
    }
    cout << i;
}