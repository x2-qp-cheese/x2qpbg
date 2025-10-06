#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    cin >> c;
    if('0' <= c && c <= '9')
        cout << 48 + c - '0';
    else if('A' <= c && c <= 'Z')
        cout << 65 + c - 'A';
    else if('a' <= c && c <= 'z')
        cout << 97 + c - 'a';
}