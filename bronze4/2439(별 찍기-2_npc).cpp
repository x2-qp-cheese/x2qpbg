#include <bits/stdc++.h>
using namespace std;

void f(int n){
    if(n == 0) return;
    f(n-1);
    cout << "*";
}

void s(int n){
    if(n == 0) return;
    s(n-1);
    cout << " ";
}

void g(int n, int total){
    if(n == 0) return;
    g(n-1, total);
    s(total-n);
    f(n);
    cout << "\n";
}

int main(){
    int n; cin >> n;
    g(n, n);
}