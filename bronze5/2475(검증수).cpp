#include <bits/stdc++.h>
using namespace std;

int main(){
    int res = 0;
    for(int i = 0; i < 5; i++){
        int tmp;
        cin >> tmp;
        res += tmp*tmp;
    }
    cout << res % 10;
}