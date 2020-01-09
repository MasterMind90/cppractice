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
int main(){
    fastio
    int n , m ; 
    cin >> n >> m ; 
    vector<int> v(n) ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
    }
    vector<int> t = v ; 
    sort(t.begin(), t.end()) ; 
    reverse(t.begin(), t.end()) ;
    multiset<int> ms ; 
    int total = 0 ; 
    for(int i = 0; i < m; i++){
        ms.insert(t[i]);
        total += t[i] ; 
    }
    int cnt = 0 ; 
    int ans = 0 ; 
    vector<int> res ; 
    for(int i = 0; i < n; i++){
        if ( (int) ms.size() == 1 ) break;
        int val = v[i] ; 
        auto it = ms.find(val) ; 
        if ( it == ms.end() ) cnt++;
        else{
            res.push_back(cnt + 1) ; 
            ans += cnt + 1 ; 
            ms.erase(it) ; 
            cnt = 0 ; 
        }
    }
    cout << total << endl;
    for(int c : res){
        cout << c << ' ' ; 
    }
    cout << n - ans << endl;
    return 0; 
}