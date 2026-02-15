#include <bits/stdc++.h>
using namespace std;

int main(){
    int l; cin >> l;
    string s; cin >> s;

    long long result = 0;
    long long hsh = 1;

    for(int i = 0; i < l; i++){
        result += (s[i] - 'a' + 1) * hsh;
        result %= 1234567891;
        hsh = (hsh * 31) % 1234567891;
    }

    cout << result;
}
