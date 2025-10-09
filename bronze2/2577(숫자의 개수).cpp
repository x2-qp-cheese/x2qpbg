#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    a*=b*c;
    while(a){
        arr[a%10]++;
        a/=10;
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    }
}