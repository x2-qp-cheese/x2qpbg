#include <bits/stdc++.h>
using namespace std;

int main(){
    list<char> editor;
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
        editor.push_back(s[i]);

    auto cursor = editor.end();

    int m;
    cin >> m;

    while(m--){
        char cmd;
        cin >> cmd;

        if(cmd == 'L'){
            if(cursor != editor.begin())
                cursor--;
        }
        else if(cmd == 'D'){
            if(cursor != editor.end())
                cursor++;
        }
        else if(cmd == 'B'){
            if(cursor != editor.begin()){
                cursor--;
                cursor = editor.erase(cursor);
            }
        }
        else if(cmd == 'P'){
            char x;
            cin >> x;
            editor.insert(cursor, x);
        }
    }

    for(char c : editor)
        cout << c;
}
