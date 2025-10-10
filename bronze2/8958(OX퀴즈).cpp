#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int tmp = 0;
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'O')
                tmp++;
            else
                tmp = 0;
            res += tmp;
        }
        cout << res << endl;
    }
}