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
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    string s ;
    cin >> s ;
    int n = (int) s.size() ; 
    vector<int> cnt(26) ; 
    vector<int> pos[26] ; 
    int nax = 0 ; 
    for(int i = 0; i < n;i++ ){
        pos[s[i] - 'a'].push_back(i) ;
        cnt[s[i] - 'a']++;
        nax = max(nax, cnt[s[i] - 'a']);
    }
    debug() << imie(nax) ;
    map<pair<int,int>, int> mp ; 
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < (int)pos[i].size(); j++){
            for(int k = 0; k < 26; k++){
                vector<int> &v = pos[k] ; 
                if ( (int) v.size() == 0 ) continue;
                int val = (int)v.size() - (upper_bound(v.begin(), v.end(), pos[i][j]) - v.begin()) ;
                mp[make_pair(i, k)] += val ; 
                nax = max(nax, mp[make_pair(i, k)]);
            }
        }
    }
    cout << nax << endl;
    return 0 ;
}
/*
a : 1 2 3 
b : 4 5
*/