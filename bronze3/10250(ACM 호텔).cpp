#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int H, W, N;
        cin >> H >> W >> N;
        int fl = N%H;
        int ro = N/H + 1;
        if(fl == 0){ 
            fl = H;
            ro--;
        }
        if(ro < 10)
            cout << fl << "0" << ro << endl;
        else
            cout << fl << ro << endl;
    }
}