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
signed main(){
    fastio
    int n , q ;
    cin >> n >> q ;
    map<int,multiset<int> > mp; 
    vector<int> belong(n) ;
    vector<int> rate(n) ;
    for(int i = 0; i < n; i++){
        int a , b ;
        cin >> a >> b ; 
        mp[b].insert(a) ;
        belong[i] = b ;
        rate[i] = a ;
    }
    multiset<int> highest ;
    for(auto &p : mp){
        auto it = p.second.end() ;
        it--;
        highest.insert(*it) ;
    }
    while(q--){
        int index , room ;
        cin >> index >> room ;
        index--;
        int curRoom = belong[index] ;
        auto &ms = mp[curRoom] ;
        // ms.erase(ms.find(rate[index])) ;
        auto it = ms.end() ;
        it--;
        if ( *it == rate[index] ){
            highest.erase(highest.find(rate[index])) ;
            ms.erase(it) ;
            if ( not ms.empty() ) {
                it = ms.end() ;
                it--;
                highest.insert(*it) ;
            }
        }
        else{
            ms.erase(ms.find(rate[index])) ;
        }

        auto &newRoom = mp[room] ;

        if ( newRoom.empty() ) {
            highest.insert(rate[index]) ;
        }
        else{
            it = newRoom.end() ;
            it--;
            if ( rate[index] > *it ){
                highest.erase(highest.find(*it)) ;
                highest.insert(rate[index]) ;
            }
        }
        newRoom.insert(rate[index]) ;
        belong[index] = room ;
        cout << *highest.begin() << endl;
    }
    return 0; 
}