#include <bits/stdc++.h>
using namespace std;

int arr[10];
bool visited[10];
int n, m; 

void NM(int selected){
    if(selected == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[selected] = i;
            NM(selected+1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    NM(0);
}