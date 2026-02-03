#include <bits/stdc++.h>
using namespace std;

int main(){
    string usr;
    cin >> usr;

    int res = 0;
    int cur = 0;  

    for(int i = 0; i < usr.size(); i++){
        if(usr[i] == '('){
            cur++;
        }
        else{
            cur--;
            if(usr[i-1] == '('){   
                res += cur;
            }
            else{                  
                res += 1;
            }
        }
    }

    cout << res;
}
