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
signed main(){
    fastio
    int n ; 
    cin >> n ; 
    vector<vector<int> > v(n - 2, vector<int>(3));
    vector<int> cnt(n + 1) ;
    map<pair<int,int>, vector<int> > mp ; 
    for(int i = 0; i < n - 2; i++){
        for(int j = 0; j < 3; j++){
            cin >> v[i][j] ; 
            cnt[v[i][j]]++;
        }
        mp[make_pair(v[i][0], v[i][1])].push_back(v[i][2]) ; 
        mp[make_pair(v[i][0], v[i][2])].push_back(v[i][1]) ; 
        mp[make_pair(v[i][1], v[i][2])].push_back(v[i][0]) ; 
    }
    vector<int> ans ; 
    for(int i = 0; i < n - 2; i++){
        for(int j = 0; j < 3; j++){
            if ( cnt[v[i][j]] == 1 ){
                ans.push_back(v[i][j]) ;
                for(int c = 0; c < 3; c++){
                    if ( cnt[v[i][c]] == 2 ){
                        ans.push_back(v[i][c]);
                        break;
                    }
                }
                for(int c = 0; c < 3; c++){
                    if ( cnt[v[i][c]] == 3 ){
                        ans.push_back(v[i][c]);
                        break;
                    }
                }
                i = n ; 
                break ; 
            }
        }
    }
    debug() << imie(ans) ;
    while((int)ans.size() < n){
        int len = (int)ans.size() ;
        int last = ans.back() ; 
        int first = ans[len - 2] ; 
        int third = ans[len - 3] ; 
        debug() << imie(first) imie(last);
        if ( mp.count(make_pair(first, last)) ){
            vector<int> &t = mp[make_pair(first, last)] ;
            if ( (int) t.size() == 1){
                if ( t[0] == third ){
                    goto done; 
                }
                else ans.push_back(t[0]) ;
            }
            else{
                if ( t[0] == third ) ans.push_back(t[1]) ;
                else ans.push_back(t[0]) ; 
            }
        }
        else{
            done:;
            vector<int> &t = mp[make_pair(last, first)] ;
            if ( t.size() == 1 ) ans.push_back(t[0]);
            else{
                if ( t[0] == third ) ans.push_back(t[1]) ;
                else ans.push_back(t[0]) ; 
            }
        }
    }
    vector<int> freq(n + 1) ;
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ' ; 
        freq[ans[i]]++;
        assert(freq[ans[i]] == 1) ;
    }
    cout << endl;
    return 0; 
}