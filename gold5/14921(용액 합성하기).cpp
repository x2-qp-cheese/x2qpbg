#include <bits/stdc++.h>
using namespace std;

int n;
int result;
int liq[100001];

int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> liq[i];
    }
    sort(liq, liq+n);
    int left = 0;
    int right = n-1;
    result = INT_MAX;
    while(left < right){
        int tmp = liq[left] + liq[right];
        if(abs(tmp) < abs(result)){
            result = tmp;
        }
        if(tmp == 0){
            cout << 0;
            return 0;
        }
        else if(tmp > 0){
            right--;
        }
        else{
            left++;
        }
    }
    cout << result;

}