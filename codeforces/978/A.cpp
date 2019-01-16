#include <bits/stdc++.h>
using namespace std;

bool f[1001];

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    stack<int> s ;
    for(int i=v.size()-1;i>=0;i--){
        if ( f[v[i]] ) continue ;
        f[v[i]] = true ;
        s.push(v[i]);
    }
    cout << s.size() << endl;
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop();
    }
    cout << endl;
    return 0 ;
}
