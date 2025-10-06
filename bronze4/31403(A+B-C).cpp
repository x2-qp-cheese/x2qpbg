#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    int d = 10;
    cin >> a >> b >> c;
    for(int i = 0; i < to_string(b).length()-1; i++){
        d*=10;
    }
    cout << a+b-c << endl;
    cout << a*d+b-c;
}