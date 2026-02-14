#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(true){
        cin >> s;
        if(s == "0") break;
        int i = 0;
        int j = s.length() - 1;
        bool flag = 1;
        while(i <= j){
            if(s[i]!=s[j]){
                flag = 0;
            }
            i++;
            j--;
        }
        if(flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}