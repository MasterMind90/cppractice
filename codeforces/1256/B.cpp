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
const ll MOD = 1e9 + 7 ;
const int N = 1e5 + 10 ;
int main(){
    fastio

    int q ;
    cin >> q ;
    while(q--){
        int n ;
        cin >> n ;
        vector<int> v(n) ;
        for(int i = 0; i < n; i++){
            cin >> v[i] ;
        }
        vector<bool> flag(n) ;
        for(int i = 0; i < n - 1; i++){
            for(int j = n - 2; j >= 0; j--){
                if ( v[j] > v[j + 1] && !flag[j] ){
                    swap(v[j], v[j + 1]);
                    flag[j] = true ;
                    break;
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout << v[i] << ' ' ;
        }
        cout << endl;
    }

    return 0 ;
}
