#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>&a, const pair<int, int>&b){
    return a.second < b.second;
}

vector<pair<int, int>> v;

int main(){
    int row, column;
    int paperNum;
    int squareNum;
    cin >> row >> column;
    cin >> paperNum;
    cin >> squareNum;

    for(int i = 0; i < squareNum; i++){
        int tmprow, tmpcol;
        cin >> tmprow >> tmpcol;
        v.push_back({tmprow, tmpcol});
    }

    sort(v.begin(), v.end(), compare);

    int left = 1;
    int right = min(row, column);
    int res = right;
    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = 1;
        int startPoint = v[0].second;
        for(int i = 1; i < squareNum; i++){
            if(v[i].first > mid){
                cnt = 10000000;
                break;
            }
            if(startPoint + mid - 1 < v[i].second){
                startPoint = v[i].second;
                cnt++;
            }
        }
        if(cnt <= paperNum){
            res = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << res;
}