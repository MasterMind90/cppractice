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
  int n , m ;
  cin >> n >> m ;
  ll sum = 0 ;
  vector<int> cnt(110,0) ;
  for(int i=0;i<n;i++){
    int x ;
    cin >> x ;
    sum += x ;
    if ( sum <= m ){
      cout << 0 << ' ' ;
      cnt[x]++ ;
      continue ;
    }
    int res = 0 ;
    int cur = sum ;
    for(int j=100;j;j--){
      if ( cnt[j] ){
        int c = (cur - m + j - 1)/j ;
        c = min(c,cnt[j]) ;
        res += c ;
        if ( cur - j*c <= m ){
          cout << res << ' ' ;
          break;
        }
        cur -= c*j ;
      }
    }
    cnt[x]++ ;
  }
  return 0 ;
}


