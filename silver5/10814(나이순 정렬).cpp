#include <bits/stdc++.h>
using namespace std;

struct Member{
    int age;
    int idx;
    string name;
};

bool cmp(const Member &a, const Member &b){
    if(a.age != b.age) return a.age < b.age;
    return a.idx < b.idx;
}

int main(){
    int n; 
    cin >> n;

    vector<Member> v;

    for(int i = 0; i < n; i++){
        Member m;
        cin >> m.age >> m.name;
        m.idx = i;
        v.push_back(m);
    }

    sort(v.begin(), v.end(), cmp);

    for(auto &m : v){
        cout << m.age << " " << m.name << "\n";
    }
}
