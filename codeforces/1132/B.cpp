#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main(){
    ll n ;
    cin >> n ;
    vector<ll> v(n) ;
    ll sum = 0 ;
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum += v[i] ; 
    }
    sort(v.begin(),v.end());
    ll m ;
    cin >> m ;
    for(int i=0;i<m;i++){
        ll q ; 
        cin >> q; 
        cout << sum - v[n-q] << endl;
    }
    return 0 ;
}
