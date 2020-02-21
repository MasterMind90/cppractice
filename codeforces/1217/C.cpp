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
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int zeros[N];
int count(int x){
    int cnt = 0 ; 
    while(x != 0){
        x /= 2; 
        cnt++ ; 
    }
    return cnt ;
}
bool isPower(int x){
    int cnt = 0 ; 
    for(int i = 0; i < 32; i++){
        if ( x & (1LL << i) ) cnt++ ;
    }
    return cnt == 1 ;
}
string toBinary(int x){
    string ans = "" ; 
    while(x != 0){
        if ( x % 2 == 0 ) ans.push_back('0');
        else ans.push_back('1') ;
        x /= 2 ;
    }
    reverse(ans.begin(), ans.end()) ;
    return ans ;
}
void solve(){
    string s ;
    cin >> s ;
    int n = (int) s.size() ;
    vector<int> sum(n + 1) ;
    for(int i = 0; i < n; i++){
        sum[i + 1] = sum[i] + (s[i] == '1') ;
    }
    // need to count 1s and 2s 
    debug() << imie(sum) ;
    int res = 0 ;
    for(int i = 0; i < n; i++){
        if ( s[i] == '1' ){
            res++ ;
            if ( i + 1 < n && s[i + 1] == '0' ) res++ ; 
        }
        if ( s[i] == '0' ){
            int L = i + 1, R = n ; 
            int ans = -1 ;
            while(L <= R){
                int mid = L + (R - L) / 2 ;
                if ( sum[mid] - sum[i] == 0 ){
                    ans = mid ; 
                    L = mid + 1 ;
                }
                else {
                    R = mid - 1;
                }
            }
            int cnt = ans - i ; 
            debug() << imie(cnt) imie(ans) ;
            int val = zeros[cnt] ;
            string t = toBinary(val) ;
            int m = (int) t.size() ;
            int c = 0 ; 
            for(int j = 0; j < m; j++){
                if ( ans + j < n && t[j] == s[ans + j] ){
                    c++ ;
                }
            }
            if ( c == m ){
                res++ ;
            }
            if ( isPower(val) ){
                t = toBinary(val - 1) ;
                m = (int) t.size() ;
                c = 0 ; 
                for(int j = 0; j < m; j++){
                    if ( ans + j < n && t[j] == s[ans + j] ){
                        c++ ;
                    }
                }
                if ( c == m ){
                    res++ ;
                }
            }
        }
    }
    cout << res << endl;
}
signed main(){
    fastio
    for(int i = 1; i <= 2e5; i++){
        zeros[i - count(i)] = i ;
    }
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}