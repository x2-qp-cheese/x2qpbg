#include <bits/stdc++.h>
using namespace std;

int main(){
    int maxnum = -1000001;
    int minnum = INT_MAX;

    int n;
    cin >> n;
    while(n--){
        int tmp;
        cin >> tmp;
        maxnum = max(tmp, maxnum);
        minnum = min(tmp, minnum);
    }
    cout << minnum << " " << maxnum;
}