#include <bits/stdc++.h>
using namespace std;


string dp[10005];

string fibo(int n){
    string res = "";
    string n_1 = dp[n-1];
    string n_2 = dp[n-2];
    int carry = 0;
    reverse(n_1.begin(), n_1.end());
    reverse(n_2.begin(), n_2.end());
    if(n_1.length() != n_2.length())
        n_2 += "0";

    for(int i = 0; i < n_1.length(); i++){
        int num = ((n_1[i] - '0') + (n_2[i] - '0') + carry) % 10;
        res += to_string(num);
        carry = ((n_1[i] - '0') + (n_2[i] - '0') + carry)/10;
    }

    if(carry != 0){
        res += to_string(carry);
    }
    reverse(res.begin(), res.end());
    return res;
}


int main(){
    int n; cin >> n;
    dp[0] = "0";
    dp[1] = "1";
   for(int i = 2; i <= n; i++){
        dp[i] = fibo(i);
   } 

   cout << dp[n];
}