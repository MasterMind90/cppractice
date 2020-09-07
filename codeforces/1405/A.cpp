#include <bits/stdc++.h>
using namespace std; 
void solve(){
    int n ; 
    cin >> n ;
    vector<int> v(n) ;
    for(int &x : v){
        cin >> x ;
    }
    reverse(v.begin(), v.end()) ;
    for(int &c : v){
        cout << c << ' ' ;
    }
    cout << endl;
}
int main(){
    int t ;
    cin >> t ;
    while(t--) {
        solve() ;
    }
    return 0 ;
}
