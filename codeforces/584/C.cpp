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
const ll N = 3e6 + 10 ;
const ll INF = 1e18 + 10 ;
int check(string a, string b){
    int cnt = 0 ; 
    for(int i = 0; i < (int) a.size(); i++){
        if ( a[i] != b[i] ) cnt++ ;
    }
    return cnt ;
}
int main(){
    fastio
    int n , t ;
    cin >> n >> t ;
    string a , b ; 
    cin >> a >> b ; 
    string c = "" ; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if ( a[i] != j + 'a' && b[i] != j + 'a' ){
                c += j + 'a';
                break ; 
            } 
        }
    }
    int same = n - t ;
    for(int i = 0; i < n; i++){
        if ( a[i] == b[i] && same ){
            c[i] = a[i] ; 
            same-- ; 
        }
    }
    int cur = same ; 
    set<int> s ; 
    for(int i = 0; i < n; i++){
        if ( a[i] != b[i] && cur ){
            c[i] = a[i] ; 
            cur-- ;
            s.insert(i) ; 
        }
    }
    cur = same ; 
    for(int i = 0; i < n; i++){
        if ( a[i] != b[i] && s.find(i) == s.end() && cur ){
            c[i] = b[i] ; 
            cur-- ;
            s.insert(i) ; 
        }
    }
    if ( check(c, a) != t || check(c, b) != t ) return cout << -1 << endl, 0 ; 
    cout << c << endl;
    return 0; 
}