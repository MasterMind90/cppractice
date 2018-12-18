#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    if ( n == 1 ) {
        cout << "YES" << endl;
        return 0 ;
    }
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        v[i] %= 2 ;
    }
    stack<int> s ;
    for(int i=0;i<n;i++){
        if ( s.empty() || v[i]!=s.top()){
            s.push(v[i]);
        }
        else s.pop();
    }
    if ( s.size() > 1 ) {
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
    return 0 ;
}
