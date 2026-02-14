#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int gajung;
    int sum = 0;
    int result = 0;

    for(int i = 0; i < 13; i++){
        if(i % 2) gajung = 3;
        else gajung = 1;

        if(s[i] == '*'){
            result = gajung;
        }
        else{
            sum += gajung * (s[i] - '0');
            sum %= 10;
        }
    }

    sum = (10 - sum) % 10;

    if(result == 1){
        cout << sum;
    }
    else{
        cout << (sum * 7) % 10;
    }
}