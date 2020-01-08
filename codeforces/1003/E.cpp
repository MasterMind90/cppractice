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
const ll N = 4e5 + 10 ;
const ll INF = 1e18 + 10 ;
vector<int> fre ; 
vector<int> deg ; 
vector<vector<int> > v ; 
int n , d , k ; 
void dfs(int x){
    queue<int> q ;
    q.push(x) ;
    while(not q.empty()){
        x = q.front() ; q.pop() ;
        if ( fre.empty() ) break;
        while(deg[x] < k){
            if ( fre.empty() ) break;
            v[x].push_back(fre.back());
            deg[x]++;
            deg[fre.back()]++;
            fre.pop_back();
        }
        for(int c : v[x]){
            q.push(c) ; 
        }
    }
}
int dp[N];
int recur(int x){
    if ( v[x].size() == 0 ) {
        return 0 ; 
    }
    if ( dp[x] != -1 ) return dp[x] ; 
    if ( x == 1 ){
        vector<int> ans; 
        for(int c : v[x]){
            ans.push_back(1 + recur(c));
        }
        debug() << imie(ans) ; 
        int nax = 0 ; 
        int index = 0 ; 
        for(int i = 0; i < (int) ans.size(); i++){
            if ( nax < ans[i] ){
                nax = ans[i] ; 
                index = i ; 
            }
        }
        int nax2 = 0 ; 
        for(int i = 0; i < (int) ans.size(); i++){
            if ( i == index ) continue ; 
            if ( nax2 < ans[i] ){
                nax2 = ans[i] ; 
            }
        }
        debug() << imie(x) imie(nax) imie(nax2) ;
        dp[x] = nax + nax2;
    }
    else{
        int ans = 0 ;
        for(int c : v[x]){
            ans = max(ans, 1 + recur(c));
        }
        dp[x] = ans ; 
    }
    return dp[x] ;
}
int main(){
    fastio
    memset(dp, -1, sizeof dp) ; 
    cin >> n >> d >> k ; 
    if ( d > n - 1 ){
        cout << "NO" << endl;
        return 0 ; 
    }
    v.resize(n + 1);
    deg.resize(n + 1);
    int dd = d ; 
    queue<int> q ; 
    if ( dd >= 2 ){
        v[1].push_back(2) ; 
        v[1].push_back(3) ; 
        deg[1]++;
        deg[2]++;
        deg[1]++;
        deg[3]++;
        dd -= 2 ;
        q.push(2) ; 
        q.push(3) ; 
    }
    else if ( dd == 1 ){
        dd -= 1 ;
        v[1].push_back(2) ; 
        deg[1]++;
        deg[2]++;
    }
    int cur = 4 ; 
    while(not q.empty()){
        int f = q.front() ; q.pop() ; 
        if ( dd > 0 ){
            v[f].push_back(cur); 
            deg[f]++;
            deg[cur]++;
            q.push(cur);
            cur++;
            dd--;
        }
    }
    for(int i = 1; i <= n; i++){
        if ( deg[i] == 0 ) fre.push_back(i);
    }
    debug() << imie(deg) ;
    dfs(1) ;
    debug() << imie(deg) ;
    for(int i = 1; i <= n; i++){
        if ( deg[i] > k || deg[i] == 0 ) {
            cout << "NO" << endl;
            return 0 ; 
        }
    }
    debug() << imie(v) ; 
    int ans = recur(1) ; 
    debug() << imie(ans) ; 
    if ( ans > d ){
        cout << "NO" << endl;
        return 0 ; 
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++){
        for(int c : v[i]){
            cout << i << ' ' << c << endl;
        }
    }
    return 0; 
}