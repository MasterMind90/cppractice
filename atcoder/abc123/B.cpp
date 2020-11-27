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
bool comp(int a , int b){
    int ma = a %10;
    int mb = b%10;
    if (ma > mb)
        return true;

    return false;
}
signed main () {
    vector<int> s1;
    vector<int> s2;
    vector<int> m(5);
    for ( int i = 0; i < 5; i++){
        cin >> m[i];
    }
    for  (int i =0 ; i < 5; i++){
        if ( m[i] %10==0){
            s1.push_back(m[i]);
        }
        else
            s2.push_back(m[i]);
    }
    sort(s2.begin(),s2.end(),comp);
    int sum = 0 ; 
    if (!s2.empty()){
        for ( int i =0; i < (int)s2.size()-1; i++){
            sum+=s2[i];
            while (sum%10!=0)
                sum++;
        }
    }
    debug() << imie(s1) ;
    debug() << imie(s2) ;
    if (!s1.empty()){
        for ( int i =0; i < (int)s1.size();i++){
            sum+=s1[i];
        }
    }
    if ( !s2.empty()){
        sum += s2[(int)s2.size()-1];
    }
    cout << sum;
}