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
const ll N = 4e5 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    int n ;
    cin >> n ;
    vector<int> p(n) , q(n) ; 
    for(int i = 0; i < n; i++){
        cin >> p[i] ; 
    }
    for(int i = 0; i < n; i++){
        cin >> q[i] ; 
    }
    vector<int> t = q ; 
    sort(t.begin(), t.end()) ; 
    int cnt = 0 ; 
    int a = 0 , b = 0 ; 
    do{
        if ( t == p ) a = cnt ; 
        if ( t == q ) b = cnt ; 
        cnt++ ; 
    }while(next_permutation(t.begin(), t.end()));
    cout << abs(a - b) << endl;
    return 0; 
}