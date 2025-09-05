#include <bits/stdc++.h>
using namespace std;

long long int arr[1000001];
long long int lis[1000001];
int res;

int binary_Search(long long target, int start, int last){
    while(start < last){
        int mid = (start + last) / 2;
        if(lis[mid] == target){
            return mid;
        }
        else if(lis[mid] < target){
            start = mid + 1;
        }
        else{
            last = mid;
        }
    }
    return last;
}

int main(){
    int n, tmp;
    cin >> n;
    cin >> tmp;
    lis[0] = tmp;
    res = 0;

    for(int i = 1; i < n; i++){
        cin >> tmp;
        if(lis[res] < tmp){
            lis[res+1] = tmp;
            res += 1; 
        }
        else{
            int pos = binary_Search(tmp, 0, res);
            lis[pos] = tmp;
        }
    }
    cout << res + 1;
}