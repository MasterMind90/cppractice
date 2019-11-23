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
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    string s ;
    cin >> s ; 
    int n = (int) s.size() ; 
    vector<int> first, second ; 
    for(int i = 0; i < n - 1; i++){
        if ( s[i] == 'A' && s[i + 1] == 'B' ) first.push_back(i) ; 
        if ( s[i] == 'B' && s[i + 1] == 'A' ) second.push_back(i) ; 
    }
    int x = (int) first.size() ; 
    int y = (int) second.size() ; 
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if ( abs(first[i] - second[j]) >= 2 ){
                return cout << "YES" << endl, 0 ; 
            }
        }
    }
    cout << "NO" << endl;
    return 0 ; 
}