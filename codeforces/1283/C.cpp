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
const ll N = 2e5 + 10 ;
const ll INF = 1e9 + 10 ;
int main(){
    fastio
    int n ; 
    cin >> n ; 
    vector<int> in(n + 1) ; 
    vector<int> out(n + 1) ; 
    vector<int> v(n + 1) ;
    for(int i = 1; i <= n; i++){
        cin >> v[i] ; 
        if ( v[i] == 0 ) continue ;
        out[i]++ ; 
        in[v[i]]++;
    }
    int pre = -1 ;
    for(int i = 1; i <= n; i++){
        if ( in[i] == 0 && out[i] == 0 ){
            if ( pre == - 1 ) {
                pre = i ; 
                continue ; 
            }
            debug() << imie(pre) imie(i) ;
            v[pre] = i ; 
            out[pre]++ ; 
            in[i]++;
            pre = i ;
        }
    }
    queue<int> give, take ; 
    int vertice = -1 ; 
    for(int i = 1; i <= n; i++){
        if ( in[i] == 0 && out[i] == 0 ){
            vertice = i ;
        }
    }
    for(int i = 1; i <= n; i++){
        if ( i == vertice ) continue ;
        if ( vertice != -1 ){
            if ( in[i] == 0 ){
                v[vertice] = i ; 
                out[vertice]++;
                in[i]++;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if ( out[i] == 0 ){
            give.push(i) ;
        }
        else if ( in[i] == 0 ){
            take.push(i) ;
        }
    }
    while(not give.empty()){
        int g = give.front() ; give.pop() ; 
        int t = take.front() ; take.pop() ; 
        v[g] = t ; 
    }
    for(int i = 1; i <= n; i++){
        assert(v[i] != i) ; 
        cout << v[i] << ' ' ; 
    }
    cout << endl;
    return 0; 
}