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
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    int n , k ; 
    cin >> n >> k ; 
    vector<pair<int,int> > v(n) ; 
    for(int i = 0; i < n; i++){
        auto &p = v[i] ; 
        cin >> p.second >> p.first ; 
    }
    sort(v.begin(), v.end()) ; 
    vector<int> sum(n) ; 
    multiset<int> s ; 
    int curSum = 0 ; 
    for(int i = 0; i < n; i++){
        int t = v[n - i - 1].second ; 
        if (s.size() < k){
            curSum += t ;
            s.insert(t) ; 
        }
        else{
            auto it = s.begin() ; 
            if (t > *it){
                curSum -= *it ; 
                curSum += t ;
                s.erase(it) ;
                s.insert(t) ;
            }
        }
        debug() << imie(s);
        sum[n - i - 1] = curSum ; 
    }
    debug() << imie(v);
    debug() << imie(sum);
    int ans = 0 ; 
    for(int i = 0; i < n; i++){
        ans = max(ans, v[i].first * v[i].second);
    }
    for(int i = 0; i < n; i++){
        debug() << imie(v[i].first * sum[i]);
        ans = max(ans, v[i].first * sum[i]);
    }
    cout << ans << endl;
    return 0 ;
}