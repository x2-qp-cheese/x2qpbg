#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main(){
    string s;
    cin >> s;
    memset(arr, -1, sizeof(arr));
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < s.length(); j++)
            if(s[j] == 'a' + i){
                arr[i] = j;
                break;
            }
    }
    for(int i = 0; i < 26; i++){
        cout << arr[i] << " ";
    }
}