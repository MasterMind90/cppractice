#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << '\n'; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
vector<int> v ;
vector<int> sum ;
void solve(){
    int n , k ; 
    cin >> n >> k ; 
    if ( n == 2 ){
        cout << "NO" << endl;
        return ; 
    }
    if ( n % 2 == 0 && k == 1 ){
        cout << "NO" << endl;
        return ;
    }
    else if ( n % 2 == 1 && k == 1 ){
        cout << "YES" << endl;
        return  ;
    }
    if ( k < sum.size() ){

        if ( sum[k] <= n ){
            if ( (n - sum[k]) % 2 == 1 ) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    else cout << "NO" << endl;
}
signed main(){
    fastio
    for(int i = 1; i < 1e7; i += 2){
        v.push_back(i) ;
    }
    sum.resize((int) v.size() + 1) ; 
    for(int i = 1; i < sum.size(); i++){
        sum[i] = sum[i - 1] + v[i - 1] ;
    }
    int t ;
    cin >> t ;
    while(t--){
        solve() ;
    }
    return 0; 
}