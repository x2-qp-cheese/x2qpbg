#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    while(n--){
        int tmp;
        cin >> tmp;
        if(tmp < x)
            cout << tmp << " ";
    }
}