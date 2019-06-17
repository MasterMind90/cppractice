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
    ll n , k ;
    cin >> n >> k ;
    vector<ll> v(n) ;
    vector<ll> sum(n+1) ;
    sum[0] = 0 ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
        sum[i+1] = sum[i] + v[i] ;
    }
    debug() << imie(sum) ;
    ll res = 0;
    for(int i=1;i<=n;i++){
        int L = i , R = n ;
        int ans = -1 ;
        while(L<=R){
            int mid = L + (R-L)/2;
            if ( sum[mid] - sum[i-1] >= k ){
                ans = mid ;
                R = mid - 1 ;
            }
            else{
                L = mid + 1 ;
            }
        }
        if ( ans == -1 ) break ;
        res += n - ans + 1 ;
    }
    cout << res << endl;


    return 0 ;
}
