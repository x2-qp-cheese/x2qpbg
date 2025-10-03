#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int sum = 0;
    string s;
    
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        sum+=s[i]-'0';
    }
    cout << sum;
}