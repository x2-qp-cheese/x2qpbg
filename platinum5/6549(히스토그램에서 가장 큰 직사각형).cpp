#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1){
        int n; cin >> n;
        if(n == 0) break;

        vector<long long> h(n+1);
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }
        h[n] = 0;

        stack<int> st;
        long long res = 0;

        for(int i = 0; i <= n; i++){
            while(!st.empty() && h[st.top()] > h[i]){
                long long height = h[st.top()];
                st.pop();

                long long width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;

                res = max(res, height * width);
            }
            st.push(i);
        }

        cout << res << '\n';
    }
}