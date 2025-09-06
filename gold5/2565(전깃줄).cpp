#include <bits/stdc++.h>
using namespace std;

pair<int, int> wire[101];
int dp[101];
int res;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> wire[i].first >> wire[i].second;
    }
    sort(wire, wire+n);
    
    dp[0] = wire[0].second;

    int last = 0;

    for(int i = 1; i < n; i++){
        if(dp[last] < wire[i].second){
            dp[last+1] = wire[i].second;
            last+=1;
        }
        else{
            int pos = lower_bound(dp, dp+last, wire[i].second) - dp;
            dp[pos] = wire[i].second;
        }
    }
    cout << n-(last+1);
}