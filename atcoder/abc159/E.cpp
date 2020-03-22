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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    int n , m , k ;
    cin >> n >> m >> k ;
    vector<string> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
    }
    int L = (n - 1) ;
    int ans = INF ;
    for(int i = 0; i < (1 << L); i++){
        vector<int> pos ;
        for(int j = 0; j < L; j++){
            if ( (1 << j) & i ) {
                pos.push_back(j) ;
            }
        }
        int div = (int)pos.size() ;
        vector<int> parts((int) pos.size() + 1);
        bool ok = true ;
        for(int col = 0; col < m; col++){
            int idx = 0 ; 
            for(int row = 0; row < n; row++){
                parts[idx] += (v[row][col] == '1');
                if ( idx < (int)pos.size() && row == pos[idx] ){
                    idx++;
                }
            }
            debug() << imie(parts) ;
            int nax = 0 ;
            for(int j = 0; j < (int)parts.size(); j++){
                nax = max(nax, parts[j]);
            }
            if ( nax > k ){
                div++;
                for(int &c : parts) c = 0 ;
                idx = 0 ;
                for(int row = 0; row < n; row++){
                    debug() << imie(row) imie(col);
                    parts[idx] += (v[row][col] == '1');
                    if ( idx < (int) pos.size() && row == pos[idx] ){
                        idx++;
                    }
                }
                debug() << "====" imie(parts);
                nax = 0 ;
                for(int j = 0; j < (int)parts.size(); j++){
                    nax = max(nax, parts[j]);
                }
                if ( nax > k ) {
                    ok = false;
                    break ;
                }
            }
        }
        if ( ok ) ans = min(ans, div) ;
    }
    cout << ans << endl;
    return 0; 
}