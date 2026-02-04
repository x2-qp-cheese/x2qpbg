#include <bits/stdc++.h>
using namespace std;
stack<char> s;
vector<char> res;

int main(){
    string usr; 
    getline(cin, usr);
    int usrlen = usr.length();
    bool flag = false;
    for(int i = 0; i < usrlen; i++){
        if(usr[i] == '<'){
            while(!s.empty()){
                res.push_back(s.top());
                s.pop();
            }
            flag = true;
            res.push_back(usr[i]);
        }else if(usr[i] == '>'){
            flag = false;
            res.push_back(usr[i]);
        }else if(usr[i] == ' '){
            while(!s.empty()){
                res.push_back(s.top());
                s.pop();
            }
            res.push_back(usr[i]);
        }else if(!flag){
            s.push(usr[i]);
        }else if(flag){
            res.push_back(usr[i]);
        }
    }
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }

    for(int i = 0; i < usrlen; i++){
        cout << res[i];
    }
}