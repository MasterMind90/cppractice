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

int main(){
    int n , k ; 
    cin >> n >> k ; 
    vector<int> v(n) ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
    }
    int res = 0 ;
    for(int i = 0; i <= min(n, k); i++){
        for(int j = 0; j + i <= min(n, k); j++){
            vector<int> ans ; 
            for(int c = 0; c < i; c++){
                ans.push_back(v[c]);
            }
            for(int c = 0; c < j; c++){
                ans.push_back(v[n - c - 1]);
            }
            sort(ans.begin(), ans.end());
            int remain = k - (i + j) ; 
            int sum = 0 ; 
            for(int c = 0; c < (int) ans.size(); c++){
                if ( ans[c] < 0 ){
                    if ( remain ){
                        remain-- ; 
                    }
                    else sum += ans[c] ; 
                }
                else sum += ans[c] ; 
            }
            res = max(res,sum) ;
        }
    }
    cout << res << endl;
    return 0 ;
}
