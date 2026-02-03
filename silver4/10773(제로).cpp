#include <bits/stdc++.h>
using namespace std;
stack<int> s;

int main(){
    int k; cin >> k;
    int sum = 0;
    while(k--){
        int n;
        cin >> n;
        if(n == 0){
            int tmp = s.top(); s.pop();
            sum-=tmp;
        }else{
            sum+=n;
            s.push(n);
        }
    }
    cout << sum;
}