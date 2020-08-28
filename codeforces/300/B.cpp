#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int long long
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
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int rep[50] ;
int Find(int x){
    if ( x == rep[x] ) return x ;
    return rep[x] = Find(rep[x]) ;
}
void Union(int x, int y){
    int X = Find(x) ;
    int Y = Find(y) ;
    if ( X == Y ) {
        return ;
    }
    rep[X] = Y ;
}
signed main(){
    fastio
    int n , m ; 
    cin >> n >> m ;
    for(int i = 0; i < 50; i++){
        rep[i] = i ;
    }
    for(int i = 0; i < m; i++){
        int a , b ;
        cin >> a >> b ; 
        a--, b-- ;
        Union(a, b) ;
    }
    vector<int> cnt(n) ;
    for(int i = 0; i < n; i++){
        cnt[Find(i)]++;
        if ( cnt[Find(i)] > 3 ) {
            cout << -1 << endl;
            return 0 ;
        }
    }
    vector<int> count(4) ;
    for(int i = 0; i < n; i++){
        count[cnt[i]]++;
    }
    if ( count[2] > count[1] ) {
        cout << -1 << endl;
        return 0 ;
    }
    int rem = count[1] - count[2] ;
    if ( rem % 3 != 0 ) {
        cout << -1 << endl;
        return 0 ;
    }
    debug() << imie(cnt) ;
    for(int i = 0; i < n; i++){
        if ( cnt[Find(i)] == 2 ) {
            for(int j = 0; j < n; j++){
                if ( cnt[Find(j)] == 1 ) {
                    Union(i, j) ;
                    break ;
                }
            }
            cnt = vector<int>(n) ;
            for(int j = 0; j < n; j++){
                cnt[Find(j)]++;
            }
            debug() << imie(cnt) ;
        }
    }
    vector<int> one ;
    for(int i = 0; i < n; i++){
        if ( cnt[Find(i)] == 1 ) {
            one.emplace_back(i + 1) ;
        }
    }
    while((int) one.size() >= 3 ){
        for(int i = 0; i < 3; i++){
            cout << one.back() << ' ' ;
            one.pop_back() ;
        }
        cout << endl;
    }
    map<int,vector<int> > mp ;
    for(int i = 0; i < n; i++){
        mp[Find(i)].emplace_back(i + 1) ;
    }
    debug() << imie(mp) ;
    for(auto &a : mp){
        if ( a.second.size() == 3 ) {
            for(int &c : a.second){
                cout << c << ' ' ;
            }
            cout << endl;
        }
    }
    return 0; 
}