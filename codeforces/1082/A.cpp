#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t ;
    cin >> t ;
    while(t--){
        ll n , x , y , d ;
        cin >> n >> x >> y >> d ;

        ll step1 = 1e18 ;

        if ( abs(y-x) % d == 0  ) step1 = abs(y-x) / d ;

        ll step2 = 1e18 ;

        if ( (y-1)%d  == 0 ) step2 = ceil((x-1)/double(d)) + (y-1)/d ;

        ll step3 = 1e18 ;

        if ( (n-y)%d == 0 )step3 = ceil((n-x)/(double)d) + (n-y)/d;

        ll ans = min(step1,step2);

        ans = min(ans,step3) ;

        if ( ans == 1e18 ) {
            cout << -1 << endl;
        }
        else cout << ans << endl;

    }

    return 0 ;
}
