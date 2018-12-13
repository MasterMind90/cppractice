#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const long long mod = 1073741824;
long long D[1000001];
ll factors(int n) {
    vector<int> f;
    ll res = 1 ;
    for (int x = 2; x*x <= n; x++) {
        ll c = 0 ;
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
            c++;
        }
        if ( c != 0 ){
            res*=(c+1LL);
        }
    }
    if (n > 1) {
        res *= (2LL);
        f.push_back(n);
    }
    return res;
}

int main(){
    ll a, b , c ;
    cin >> a >> b >> c ;
    ll sum = 0LL ;
    for(ll i=1;i<=a;i++){
        for(ll j=1;j<=b;j++){
            for(ll k=1;k<=c;k++){
                ll res = i * j * k ;
                ll ans = factors(res);
                if ( D[res] == 0 ){
                    sum = ((sum%mod) + (ans%mod))%mod;
                    D[res] = ans ;
                }
                else{
                    sum = ((sum%mod) + (D[res]%mod))%mod ;
                }
            }
        }
    }
    cout << sum << endl;

    return 0 ;
}
