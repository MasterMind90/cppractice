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
~debug() { cerr << endl; }
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
const int MAXN = 1e5 + 10 ;
int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
    }
    int cnt[MAXN] = {0} ;
    int nax = 0 ;
    int first = -1 ;
    for(int i=0;i<n;i+=2){
        cnt[v[i]]++;
        if ( nax < cnt[v[i]] ){
            nax = max(nax,cnt[v[i]]) ;
            first = v[i] ;
        }
    }
    int ans1 = n/2 - nax ;
    int secondNax = 0 ;
    for(int i=0;i<MAXN;i++){
        if ( i == first ) continue ;
        secondNax = max(secondNax,cnt[i]) ;
    }
    memset(cnt,0,sizeof cnt) ;
    nax = 0 ;
    int second = -1 ;
    for(int i=1;i<n;i+=2){
        cnt[v[i]]++;
        if ( nax < cnt[v[i]] ){
            nax = max(nax,cnt[v[i]]) ;
            second = v[i] ;
        }
    }
    int ssNax = 0 ;
    for(int i=0;i<MAXN;i++){
        if ( i == second ) continue ;
        ssNax = max(ssNax,cnt[i]) ;
    }
    int ans2 = (n/2 - nax) ;
    if ( first == second ){
        debug() << imie(first) imie(second) ;
        debug() << imie(secondNax) imie(ssNax);
        cout << min(ans2+n/2-secondNax,ans1+n/2-ssNax) << endl;
        return 0 ;
    }
    cout << ans1 + ans2 << endl;
    return 0 ;
}

