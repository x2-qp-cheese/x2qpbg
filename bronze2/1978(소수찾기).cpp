#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int result = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        bool chk = true;
        if(num == 1) continue;
        if(num == 2){
            result++;
            continue;
        }
        for(int i = 2; i*i <= num; i++){
            if(num%i == 0){
                chk = false;
                break;
            }
        }
        if(chk) result++;
    }
    cout << result;
}