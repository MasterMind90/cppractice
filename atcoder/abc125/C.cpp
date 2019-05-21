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
typedef long long ll;

ll gcd(ll a,ll b){
    if ( b == 0 ) return a ;
    return gcd(b,a%b);
}

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int &x : v){
        cin >> x ;
    }
    vector<int> left(n+1) ;
    vector<int> right(n+1) ;
    left[0] = 0 ;
    right[n] = 0 ;
    for(int i=0;i<n;i++){
        left[i+1] = gcd(left[i],v[i]);
    }
    for(int i=n-1;i>=0;i--){
        right[i] = gcd(right[i+1],v[i]);
    }
    debug() << imie(left) ;
    debug() << imie(right) ;
    int nax = right[0] ;
    debug() << imie(nax) ;
    for(int i=1;i<=n;i++){
        int ans = gcd(left[i-1],right[i]);
        nax = max(nax,ans);
        debug() << imie(nax) ;
    }
    cout << nax << endl;
    return 0 ;
}
