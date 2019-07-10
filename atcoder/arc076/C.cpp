#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7 ;
int main(){
    long long n , m ;
    cin >> n >> m ;
    if ( abs(n-m) >= 2 ){
        cout << 0 << endl;
        return 0 ;
    }
    if ( m > n ) swap(n,m) ;
    long long ans = 1;
    if ( n > m ) {
        for(long long i=n;i>=2;i--){
            ans = (((ans % mod * i % mod) % mod) * (i-1) % mod) % mod ;
        }
        cout << ans << endl;
        return 0 ;
    }
    for(long long i=n;i>=2;i--){
        ans = (((ans % mod * i % mod) % mod) * i % mod) % mod ;
    }
    ans = (ans % mod + ans % mod) % mod;
    cout << ans << endl;
    return 0 ;
}