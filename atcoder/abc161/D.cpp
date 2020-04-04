#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
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
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
vector<int> ans ; 
int d(int x){
    int cnt = 0 ; 
    while(x != 0){
        x /= 10 ; 
        cnt++ ; 
    }
    return cnt ; 
}
void gen(int x, int len){
    if ( d(x) > len ) return ;
    if ( d(x) == len ){
        ans.push_back(x) ; 
        return ;
    }
    if ( x == 0 ){
        for(int i = 1; i < 10; i++){
            gen(10 * x + i, len) ; 
        }
    }
    else{
        int lastDigit = x % 10 ; 
        if ( lastDigit == 0 ){
            gen(10 * x, len) ; 
            gen(10 * x + 1, len) ; 
        }
        else if ( lastDigit == 9 ){
            gen(10 * x + 8, len) ; 
            gen(10 * x + 9, len) ; 
        }
        else{
            for(int i = lastDigit - 1; i <= lastDigit + 1; i++){
                gen(10 * x + i, len);
            }
        }
    }
}
signed main(){
    fastio 
    for(int i = 1; i <= 10; i++){
        gen(0, i);
    }
    int k ; 
    cin >> k ; 
    cout << ans[k - 1] << endl;
    return 0 ; 
}