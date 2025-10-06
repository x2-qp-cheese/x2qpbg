#include <bits/stdc++.h>
using namespace std;

int main(){
    int maxnum = -1;
    int idx = 0;

    for(int i = 1; i <= 9; i++){
        int tmp;
        cin >> tmp;
        if(tmp > maxnum){
            maxnum = tmp;
            idx = i;
        }
    }
    cout << maxnum << endl;
    cout << idx << endl;
}