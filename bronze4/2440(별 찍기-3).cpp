#include <bits/stdc++.h>
using namespace std;


void f(int n){
    if(n == 0) return;
    f(n-1);
    cout << "*";
}


void g(int n){
    if(n == 0) return;
    f(n);
    cout << "\n";
    g(n-1);
}

int main(){
    int n; cin >> n;
    g(n);
}