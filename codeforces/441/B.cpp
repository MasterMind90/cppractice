#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
ll cnt[3005] ;
int main(){
    ll n , v = 0LL;
    cin >> n >> v ;
    for(int i=1;i<=n;i++){
        ll x , y ;
        cin >> x >> y ;
        cnt[x]+=y;
    }
    ll ans = 0LL ;
    for(int i=1;i<=3002;i++){
        ll x = min(cnt[i-1],v);
        ans += x ;
        ll remain = v-x;
        ll vv = min(cnt[i],remain);
        ans += vv;
        cnt[i] -= vv ;
    }
    cout << ans << endl;

    return 0 ;
}
