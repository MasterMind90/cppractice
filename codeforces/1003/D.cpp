#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , q ;
    cin >> n >> q ;
    map<long long, long long> m ;

    for(int i=0;i<n;i++){
        long long x ;
        cin >> x ;
        m[x]++;
    }
    while(q--){
        long long x ;
        cin >> x ;
        auto it = m.lower_bound(x);
        if ( it == m.end() ) it--;
        int ans = 0 ;
        for(;it!=m.begin();it--){
            long long mm = min(x/it->first,it->second);
            ans += mm ;
            x = x - mm*it->first ;
        }
        long long mm = min(x/it->first,it->second);
        ans += mm ;
        x = x - mm*it->first ;
        if ( x == 0 ) {
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0 ;
}
