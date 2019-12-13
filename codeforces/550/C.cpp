#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
~debug() { cerr << endl; }
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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
const ll INF = 1e9 + 10 ;
const int N = 110 ; 
bool isSub(string x, string &y){
    int m = (int) x.size()  ;
    int n = (int) y.size() ; 
    int posx = 0 ; 
    for(int i = 0; i < n; i++){
        if ( y[i] == x[posx] ) posx++;
    }
    if ( posx == m ) return true ; 
    return false ;
}
int main(){
    fastio
    string s ;
    cin >> s ;
    vector<string> total;
    total.push_back("0") ; 
    for(int i = 8; i < 1000; i += 8){
        int x = i;
        string tmp = "" ; 
        while(x != 0){
            tmp = char(x % 10 + '0') + tmp ; 
            x /= 10 ; 
        }
        total.push_back(tmp) ; 
    }
    for(string &v : total){
        if ( isSub(v, s) ){
            cout << "YES" << endl;
            cout << v << endl;
            return 0 ; 
        }
    }
    cout << "NO" << endl;
    return 0 ;
}