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
using ll = long long ;
int main(){
    ll n , d ;
    cin >> n >> d ;
    vector<pair<ll,ll> > v(n) ;
    vector<ll> sum(n+1) ;
    sum[0] = 0 ;
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second ;
        v[i].second = -v[i].second ;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        sum[i+1] = sum[i] + -v[i].second ;
    }
    debug() << imie(v) ;
    debug() << imie(sum) ;
    ll res = 0 ;
    for(int i=0;i<n;i++){
        res = max(res,-v[i].second) ; 
        int L = 0 , R = n - 1 ;
        int ans = -1 ;
        while(L<=R){
            int mid = L + (R-L)/2 ;
            if ( v[mid].first < v[i].first+d ){
                ans = mid ;
                L = mid + 1 ;
            }
            else R = mid - 1 ;
        }
        debug() << imie(ans) ;
        if ( ans != -1 )
            res = max(res,sum[ans+1]-sum[i]);
    }
    cout << res << endl;
    return 0 ;
}
