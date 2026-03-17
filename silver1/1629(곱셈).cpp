#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int multiply(int B){
    if(B == 0) return 1;

    long long tmp = multiply(B/2);
    tmp = (tmp*tmp) % c;
     
    if(B%2 == 0) 
        return tmp;
    else
        return (tmp * a) % c;
}

int main(){
    cin >> a >> b >> c;

    int res = multiply(b);
    cout << res;
}