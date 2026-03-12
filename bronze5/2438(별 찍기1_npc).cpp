#include <bits/stdc++.h>
using namespace std;

void f(int n){
    if(n == 0) return;
    f(n-1);
    cout << "*";
}

void g(int n){
    if(n == 0) return;
    g(n-1);
    f(n);
    cout << "\n";
}

int main(){
    int n; cin >> n;
    g(n);
}