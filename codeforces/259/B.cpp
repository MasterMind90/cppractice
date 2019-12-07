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
const ll N = 1e5 + 1 ;
const ll INF = 1e18 + 10 ;
const double pi = acos(-1) ; 
int v[3][3] ; 
int n = 3; 
bool check(){
    set<int> s ; 
    for(int i = 0; i < 3; i++){
        int sum = 0 ; 
        for(int j = 0; j < 3; j++){
            sum += v[i][j] ; 
        }
        s.insert(sum) ; 
    }
    for(int i = 0; i < 3; i++){
        int sum = 0 ; 
        for(int j = 0; j < 3; j++){
            sum += v[j][i] ; 
        }
        s.insert(sum) ; 
    }
    int sum = 0 ; 
    for(int i = 0; i < 3; i++){
        sum += v[i][i] ; 
    }
    s.insert(sum) ; 
    sum = 0; 
    for(int i = 0; i < 3; i++){
        sum += v[i][n - i - 1] ; 
    }
    s.insert(sum) ; 
    if ( (int)s.size() == 1 ) return true ; 
    return false ;
}
int main(){
    fastio
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> v[i][j] ; 
        }
    }
    for(int i = 1; i < N; i++){
        v[0][0] = i ; 
        int sum = 0 ; 
        for(int j = 0; j < 3; j++){
            sum += v[0][j] ; 
        }
        v[1][1] = sum - v[0][1] - v[2][1] ; 
        v[2][2] = sum - v[2][0] - v[2][1] ; 
        if ( check() ){
            for(int x = 0; x < 3; x++){
                for(int y = 0; y < 3; y++){
                    cout << v[x][y] << ' ' ; 
                }
                cout << endl;
            }
            return 0 ; 
        }
    }
    return 0; 
}