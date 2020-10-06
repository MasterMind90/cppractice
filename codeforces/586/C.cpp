#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define int long long
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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 1 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio;
    int n ;
    cin >> n ;
    vector<int> v(n) , d(n), p(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] >> d[i] >> p[i] ;
    }
    int ans = 0 ;
    vector<int> answer ;
    vector<int> used(n) ;
    for(int i = 0; i < n; i++){
        if ( used[i] ) continue ;
        queue<int> q ;
        if ( p[i] >= 0 ) {
            ans++ ;
            answer.emplace_back(i + 1) ;
            int cnt = 0 ; 
            int j = 0 ; 
            while(cnt < v[i] && i + j + 1 < n){
                if ( used[i + j + 1] ) j++ ;
                else{
                    p[i + j + 1] -= v[i] - cnt ;
                    if ( p[i + j + 1] < 0 ) {
                        used[i + j + 1] = true ;
                        q.push(i + j + 1) ;
                    }
                    j++ ;
                    cnt++ ;
                }
            }
            //for(int j = 0; j < v[i] && i + j + 1 < n; j++){
            //    if ( used[i + j + 1] ) continue ;
            //    p[i + j + 1] -= v[i] - j ;
            //    if ( p[i + j + 1] < 0 ) {
            //        used[i + j + 1] = true ;
            //        q.push(i + j + 1) ;
            //    }
            //}
        }
        while(not q.empty()){
            int f = q.front() ; q.pop() ;
            for(int j = f + 1; j < n; j++){
                if ( used[j] ) continue ;
                p[j] -= d[f] ;
                if ( p[j] < 0 ) {
                    used[j] = true ;
                    q.push(j) ;
                }
            }
        }
    }
    cout << ans << endl;
    for(int &c : answer){
        cout << c << ' ' ;
    }
    cout << endl;
    return 0; 
}
