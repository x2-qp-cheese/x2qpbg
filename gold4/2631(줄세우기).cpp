#include <bits/stdc++.h>
using namespace std;


int dp[201];
int res;

int binary_search(int target, int left, int right){
    while(left < right){
        int mid = (left+right) / 2;
        if(target > dp[mid])
            left = mid + 1;
        else
            right = mid;
    }   
    return right;
}

int main(){
    int n;
    int tmp;

    cin >> n;
    cin >> tmp;
    dp[0] = tmp;
    res = 0;
    for(int i = 1; i < n; i++){
        cin >> tmp;
        if(dp[res] < tmp){
            dp[res+1] = tmp;
            res+=1;
        }
        else{
            int pos = binary_search(tmp, 0, res);
            dp[pos] = tmp;
        }
    }
    cout << n - (res + 1);
}