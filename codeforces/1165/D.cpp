#include <bits/stdc++.h>
using namespace std;
vector<int> get(long long x){
    set<int> s ;
    for(long long i=1;i*i<=x;i++){
        if ( x % i == 0 ){
            s.insert(i) ;
            s.insert(x/i);
        }
    }
    s.erase(1);
    s.erase(x);
    vector<int> v(s.begin(),s.end());
    return v ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        vector<int> v(n) ;
        for(int i=0;i<n;i++){
            cin >> v[i] ;
        }
        sort(v.begin(),v.end());
        long long val = v[0] * 1LL * v[n-1];
        vector<int> div = get(val) ;
        if ( div == v ){
            cout << val << endl;
        }
        else cout << -1 << endl;
    }
    return 0 ;
}
