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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
void read(int& x){
    scanf("%I64d", &x);
}
int f(int v, int p){
    return v * p / 100 ;
}
int lcm(int a, int b){
    return a * b / __gcd(a, b) ;
}
void solve(){
    int n ;
    // cin >> n ;
    read(n);
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
        // cin >> v[i] ;
        read(v[i]);
    }
    int x , a ;
    // cin >> x >> a ;
    read(x) ;
    read(a) ;
    int y , b ; 
    // cin >> y >> b ; 
    read(y) ;
    read(b) ;
    int k ;
    // cin >> k ;
    read(k);
    sort(v.begin(), v.end()) ;
    reverse(v.begin(), v.end());
    int L = 1 , R = n ; 
    int ans = -1 ;
    while(L <= R){
        int mid = L + (R - L) / 2 ;
        int both = mid / lcm(a , b) ;
        int onlyA = mid / a - both ; 
        int onlyB = mid / b - both ;
        assert(both + onlyA + onlyB <= n) ;
        int cur = 0 ; 
        int sum = 0 ; 
        debug() << imie(both) imie(onlyA) imie(onlyB) ;
        for(int i = 0; i < both; i++){
            sum += f(v[cur++], x + y) ;
        }
        int t = cur ; 
        int sum1 = 0 ; 
        for(int i = 0; i < onlyA; i++){
            sum1 += f(v[t++], x) ;
        }
        for(int i = 0; i < onlyB; i++){
            sum1 += f(v[t++], y) ;
        }
        int sum2 = 0 ; 
        for(int i = 0; i < onlyB; i++){
            sum2 += f(v[cur++], y) ;
        }
        for(int i = 0; i < onlyA; i++){
            sum2 += f(v[cur++], x) ;
        }
        sum += max(sum1, sum2) ;
        debug() << imie(mid) imie(sum) ;
        if ( sum >= k ){
            ans = mid ; 
            R = mid - 1;
        }
        else L = mid + 1;
    }
    // cout << ans << endl;
    printf("%I64d\n", ans);
}
signed main(){
    //fastio
    int t; 
    // cin >> t ;
    read(t);
    while(t--) solve() ;
    return 0; 
}