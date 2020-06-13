#ifndef LOCAL
#pragma GCC optimize("O3")
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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
vector<int> nix(N);
map<int,int> factors(int x){
    map<int,int> mp ;
    while(x != 1){
        mp[nix[x]]++;
        x /= nix[x] ;
    }
    return mp ;
}
signed main(){
    fastio
    for(int i = 2; i * i <= N; i++){
        if ( nix[i] == 0 ){
            for(int j = i; j < N; j += i){
                if ( nix[j] == 0 ) nix[j] = i ;
            }
        }
    }
    for(int i = 2; i < N; i++){
        if ( nix[i] == 0 ) nix[i] = i ;
    }
    int n ;
    cin >> n ;
    vector<int> a , b ;
    for(int i = 0; i < n; i++){
        int x ;
        cin >> x ;
        map<int,int> v = factors(x);
        if ( v.size() <= 1 ){
            a.emplace_back(-1) ;
            b.emplace_back(-1) ;
        }
        else{
            int cnt = 0 ;
            int first = 0, last = 1 ;
            for(auto &p : v){
                if ( cnt == 0 ){
                    first = p.first ;
                }
                else last *= p.first ;
                cnt++;
            }
            a.emplace_back(first) ;
            b.emplace_back(last) ;
        }
    }
    for(int &c : a){
        cout << c << ' ' ;
    }
    cout << endl;
    for(int &c : b){
        cout << c << ' ' ;
    }
    cout << endl;
    return 0; 
}