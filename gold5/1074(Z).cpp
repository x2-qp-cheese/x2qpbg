#include <bits/stdc++.h>
using namespace std;

long long solve(int n, int r, int c) {
    if (n == 0) return 0;
    
    long long half = 1LL << (n - 1); 
    long long area_size = half * half;

    if (r < half && c < half) 
        return solve(n - 1, r, c);             
    if (r < half && c >= half) 
        return area_size + solve(n - 1, r, c - half);
    if (r >= half && c < half) 
        return 2 * area_size + solve(n - 1, r - half, c);
    
    return 3 * area_size + solve(n - 1, r - half, c - half);
}

int main(){    
    int n, r, c;
    cin >> n >> r >> c;
    
    cout << solve(n, r, c) << endl;
    
    return 0;
}