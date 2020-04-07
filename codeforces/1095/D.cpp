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
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    int n ;
    cin >> n ; 
    vector<int> a(n + 1) , b(n + 1) ;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] ;
    }
    vector<int> p(n + 1) ;
    p[1] = 1 ;
    p[2] = a[1] ;
    if ( a[p[2]] == b[1] || b[p[2]] == b[1] ){
        p[3] = b[1] ;
    }
    else{
        p[2] = b[1] ;
        p[3] = a[1] ;
    }
    for(int i = 2; i + 2 <= n; i++){
        if ( a[p[i]] == a[p[i + 1]] ){
            p[i + 2] = a[p[i]];
        }
        else if ( a[p[i]] == b[p[i + 1]] ){
            p[i + 2] = a[p[i]];
        }
        else if ( b[p[i]] == a[p[i + 1]] ){
            p[i + 2] = b[p[i]];
        }
        else if ( b[p[i]] == b[p[i + 1]] ){
            p[i + 2] = b[p[i]];
        }
    }
    for(int i = 1; i < n + 1; i++){
        cout << p[i] << ' ' ;
    }
    cout << endl;
    return 0 ;
}
// 5 2 4 1 3
// 3 2 4 1 5