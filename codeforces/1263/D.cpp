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
const ll N = 30;
const ll INF = 1e18 + 10 ;
int rep[N] ; 
int Find(int x){
    if ( x == rep[x] ) return x ; 
    rep[x] = Find(rep[x]) ; 
    return rep[x] ; 
}
void Union(int x,int y){
    int X = Find(x) ; 
    int Y = Find(y) ; 
    if ( X == Y ) return ; 
    rep[X] = Y ; 
}
int main(){
    fastio
    for(int i = 0; i < N; i++){
        rep[i] = i ; 
    }
    int n ; 
    cin >> n ; 
    vector<string> v(n) ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
        string s ;
        s = v[i] ; 
        int m = (int) s.size() ; 
        for(int j = 1; j < m; j++){
            Union(s[j] - 'a', s[j - 1] - 'a') ; 
        }
    }
    set<int> s ; 
    for(int i = 0; i < n; i++){
        for(char c : v[i]){
            debug() << imie(c) imie(Find(c - 'a')) ; 
            s.insert(Find(c - 'a')) ; 
        }
    }
    cout << (int)s.size() << endl;
    return 0; 
}
