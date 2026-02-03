#include <bits/stdc++.h>
using namespace std;
stack<char> s;


int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        string usr; 
        cin >> usr;
        bool flag = true;
        for(int i = 0; i < usr.size(); i++){
            if(usr[i] == '('){
                s.push('(');
            }else{
                if(s.empty()){
                    flag = false;
                }else{
                    s.pop();
                }
            }
        }
        if(!s.empty()){
            flag = false;
            while(!s.empty())
                s.pop();
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;


    }
}