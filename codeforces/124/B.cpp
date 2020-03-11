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
    int n , k ;
    cin >> n >> k; 
    vector<string> v(n) ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    vector<int> p ; 
    for(int i = 0; i < k; i++){
        p.push_back(i) ; 
    }
    auto power = [&](int x, int y){
        int ans = 1 ;
        for(int i = 0; i < y; i++){
            ans *= x ; 
        }
        return ans ; 
    };
    auto toNumber = [&](vector<char>& x){
        int ans = 0 ; 
        for(int j = 0; j < k; j++){
            ans += power(10, j) * (x[k - j - 1] - '0');
        }
        return ans ; 
    };
    int ans = INF ;
    do{
        vector<int> s ; 
        for(int j = 0; j < n; j++){
            vector<char> t(k) ; 
            for(int i = 0; i < k; i++){
                t[p[i]] = v[j][i] ;  
            }
            s.push_back(toNumber(t)) ;
        }
        sort(s.begin(), s.end()) ; 
        debug() << imie(s) imie(s[n - 1] - s[0]) ;
        ans = min(ans, s[n - 1] - s[0]);
    }while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0; 
}