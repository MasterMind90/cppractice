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
const double EPS = 1e-6 ; 
signed main(){
    fastio
    int s , b ; 
    cin >> s >> b ; 
    vector<int> v(s) ;
    for(int i = 0; i < s; i++){
        cin >> v[i] ;
    }
    vector<pair<int,int> > bases(b) ; 
    for(int i = 0; i < b; i++){
        cin >> bases[i].first >> bases[i].second ; 
    }
    sort(bases.begin(), bases.end());
    vector<int> sum(b + 1) ;
    for(int i = 0; i < b; i++){
        sum[i + 1] = sum[i] + bases[i].second ;
    }
    for(int i = 0; i < s; i++){
        int val = v[i] ; 
        int L = 0, R = b - 1 ; 
        int ans = -1 ; 
        while(L <= R){
            int mid = L + (R - L) / 2 ;
            if ( bases[mid].first <= val ){
                ans = mid ; 
                L = mid + 1 ;
            }
            else R = mid - 1 ;
        }
        if ( ans == -1 ){
            cout << 0 << ' ' ; 
        }
        else{
            cout << sum[ans + 1] << ' ' ; 
        }
    }
    cout << endl;
    return 0; 
}