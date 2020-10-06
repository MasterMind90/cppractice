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
const ll MOD = 998244353 ;
//const ll MOD = 1e9 + 7 ;
const ll N = 3e5 + 1 ;
const ll INF = 1e18 + 10 ;
vector<int> fact(N) ;
vector<int> inv(N) ;
int fast(int a, int b){
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return a ;
    int y = fast(a, b / 2) ;
    y = y * 1LL * y % MOD ; 
    if ( b & 1 ) y = y * 1LL * a % MOD ;
    return y ;
}
void init(){
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = i * 1LL * fact[i - 1] % MOD ;
    }
    inv[N - 1] = fast(fact[N - 1], MOD - 2) ;
    for(int i = N - 2; i >= 0; i--){
        inv[i] = inv[i + 1] * 1LL * (i + 1) % MOD ;
    }
}
int C(int n, int k){
    int ans = fact[n] ;
    ans = ans * 1LL * inv[n - k] % MOD ;
    ans = ans * 1LL * inv[k] % MOD ;
    return ans ;
}
signed main(){
    fastio;
    init() ;
    int n , k ; 
    cin >> n >> k ;
    vector<pair<int,int> > v(n) ;
    vector<pair<int,int> > all ;
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second ;
        all.emplace_back(v[i].first, 1) ;
        all.emplace_back(v[i].second + 1, -1) ;
    }
    sort(all.begin(), all.end()) ;
    int answer = 0 ;
    int cnt = 0 ;
    for(int i = 0; i < (int)all.size(); i++){
        debug() << imie(cnt) ;
        if ( all[i].second == 1 ) {
            if ( cnt >= k - 1 ) answer += C(cnt, k - 1) ;
        }
        cnt += all[i].second ;
        answer %= MOD ;
    }
    cout << answer << endl;
    return 0; 
}

//
//                                                            
//      ----                                                  
//       -------------                          
//        -------------------                                                    
//            ---------                                                
//               -------------------                          
//                             -----                         
//                                                            
//                                                            
//                                                            
//                                                            
//                                                            
//                                                            
//  1234567890                                                
//  XXX                                                       
//  XXXXXXX                                                   
//    XXXXXX                                                  
//     XX                                                     
//      XXXXXX                                                
//       XX                                                   
//         XX                                               
//                                                            
//  1234567890                                                
//  XXX                                                       
//     XX                                                     
//       XX                                                   
//  XXXXXXX                                                   
//    XXXXXX                                                  
//         XX                                               
//      XXXXXX                                                
//                                                            
