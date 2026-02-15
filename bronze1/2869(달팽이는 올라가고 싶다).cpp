#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, v;
    cin >> a >> b>> v;

    int result = (v-a) / (a-b) + 1;
    if((v-a) % (a-b)){
        result+=1;
    }
    cout << result;

}