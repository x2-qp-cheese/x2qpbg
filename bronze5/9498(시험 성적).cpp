#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n < 60)
        cout << "F";
    else if(n < 70)
        cout << "D";
    else if(n < 80)
        cout << "C";
    else if(n < 90)
        cout << "B";
    else
        cout << "A";
}