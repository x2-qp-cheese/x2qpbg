#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    double mx = 0;
    double sum = 0;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        sum+=num;
        if(mx < num) mx = num;
    }
    double res = sum / mx * 100;
    res /= n;
    cout << res;
}