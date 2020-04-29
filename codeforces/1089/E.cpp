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
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
string decode(pair<int,int> p){
    char col = p.second + 'a' - 1 ;
    string ans = "" ;
    ans.push_back(col) ;
    ans.push_back(p.first + '0') ; 
    return ans ;
}
signed main(){
    fastio
    int n ; 
    cin >> n ;
    vector<pair<int,int> > ans ; 
    for(int x = 1; x < 9; x++){
        for(int y = 1; y < 6; y++){
            if ( x & 1 ){
                ans.push_back(make_pair(x, y));
            }
            else ans.push_back(make_pair(x, 6 - y));
        }
    }
    for(int i = 1; i < 9; i++){
        ans.push_back(make_pair(9 - i, 6));
    }
    ans.push_back(make_pair(1, 8));
    ans.push_back(make_pair(1, 7));
    ans.push_back(make_pair(2, 7));
    ans.push_back(make_pair(2, 8));
    ans.push_back(make_pair(3, 8));
    ans.push_back(make_pair(3, 7));
    ans.push_back(make_pair(4, 7));
    ans.push_back(make_pair(4, 8));
    ans.push_back(make_pair(5, 8));
    ans.push_back(make_pair(5, 7));
    ans.push_back(make_pair(6, 7));
    ans.push_back(make_pair(8, 7));
    ans.push_back(make_pair(7, 7));
    ans.push_back(make_pair(7, 8));
    ans.push_back(make_pair(6, 8));
    ans.push_back(make_pair(8, 8));
    if ( n == 2 ){
        cout << "a1 h1 h8" << endl; 
    }
    else if ( n == 63 ){
        for(auto &p : ans){
            cout << decode(p) << ' ' ;
        }
        cout << endl;
    }
    else if ( n == 62 ){
        ans.pop_back() ;
        ans.pop_back() ;
        ans.pop_back() ;
        ans.pop_back() ;
        ans.pop_back() ;
        ans.push_back(make_pair(8, 7));
        ans.push_back(make_pair(7, 7));
        ans.push_back(make_pair(7, 8));
        ans.push_back(make_pair(8, 8));
        for(auto &p : ans){
            cout << decode(p) << ' ' ;
        }
        cout << endl;
    }
    else if ( n == 61 ){
        ans.pop_back() ;
        ans.pop_back() ;
        ans.pop_back() ;
        ans.pop_back() ;
        ans.pop_back() ;
        ans.push_back(make_pair(6, 8));
        ans.push_back(make_pair(7, 8));
        ans.push_back(make_pair(8, 8));
        for(auto &p : ans){
            cout << decode(p) << ' ' ;
        }
        cout << endl;
    }
    else if ( n == 60 ){
        ans.pop_back() ;
        ans.pop_back() ;
        ans.pop_back() ;
        ans.pop_back() ;
        ans.pop_back() ;
        ans.push_back(make_pair(6, 8));
        ans.push_back(make_pair(8, 8));
        for(auto &p : ans){
            cout << decode(p) << ' ' ;
        }
        cout << endl;
    }
    else {
        vector<pair<int,int> > t ; 
        for(int i = 0; i <= n - 2; i++){
            t.push_back(ans[i]) ;
        }
        debug() << imie(t) ;
        if ( t.back().first == 8 ){
            t.push_back(make_pair(8, 7));
            t.push_back(make_pair(8, 8));
        }
        else if ( t.back().second == 8 ){
            t.push_back(make_pair(7, 8));
            t.push_back(make_pair(8, 8));
        }
        else if ( t.back().second == 7 ) {
            t.push_back(make_pair(8, 7));
            t.push_back(make_pair(8, 8));
        }
        else{
            t.push_back(make_pair(t.back().first, 8));
            t.push_back(make_pair(8, 8));
        }
        for(auto &p : t){
            cout << decode(p) << ' ' ;
        }
        cout << endl;
    }
    return 0; 
}