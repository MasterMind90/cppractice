#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
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
int main(){
    fastio
    int n , m ; 
    cin >> n >> m ; 
    vector<pair<int,pair<int,pair<int,int> > > > v(m) ; 
    for(int i = 0; i < m; i++){
        int s , d , c ; 
        cin >> s >> d >> c ;
        v[i].first = d ; 
        v[i].second.first = s ; 
        v[i].second.second.first = c ; 
        v[i].second.second.second = i + 1 ; 
    }
    sort(v.begin(), v.end()) ; 
    vector<int> ans(n + 1) ; 
    for(int day = 1; day <= n; day++){
        for(int i = 0; i < m; i++){
            if ( v[i].first < day ) continue ; 
            if ( v[i].first == day ){
                if ( v[i].second.second.first != 0 ){
                    cout << -1 << endl;
                    return 0 ; 
                }
                ans[day] = m + 1 ;
                break ; 
            }
            if ( day >= v[i].second.first && v[i].second.second.first > 0 ){
                ans[day] = v[i].second.second.second ;
                v[i].second.second.first-- ; 
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ' ; 
    }
    cout << endl;
    return 0; 
}