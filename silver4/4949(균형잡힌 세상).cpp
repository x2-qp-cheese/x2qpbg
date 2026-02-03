#include <bits/stdc++.h>
using namespace std;
stack<char> stk;

int main(){

    while(true){
        string s;
        getline(cin, s);
        if(s == ".") 
            break;
        
        int sz = s.size();
        bool flag = true;
        for(int i = 0; i < sz; i++){
            if(s[i] == '(' || s[i] == '[')
                stk.push(s[i]);
            else if(s[i] == ')'){
                if(stk.empty() || stk.top() != '('){
                    flag = false;
                    break;
                }
                stk.pop();
            }
            else if(s[i] == ']'){
                if(stk.empty() || stk.top() != '['){
                    flag = false;
                    break;
                } 
                stk.pop();
            }
        }
        if(!stk.empty())
            flag = false;
        if(flag)
            cout << "yes\n";
        else
            cout << "no\n";

        while(!stk.empty())
            stk.pop();
    }
}