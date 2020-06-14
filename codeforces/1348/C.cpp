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
void solve(){
    int n , k ;
    cin >> n >> k ;
    string s ;
    cin >> s ;
    if ( k == 1 ){
        sort(s.begin(), s.end()) ;
        cout << s << endl;
        return ;
    }
    vector<int> cnt(26) ;
    set<char> se ;
    for(char &c : s){
        se.insert(c) ;
        cnt[c - 'a']++;
    }
    if ( se.size() == 1 ){  // aaaaaaaaaaa 
        string ans((n + k - 1) / k , s[0]) ;
        cout << ans << endl;
        return ;
    }
    // aaabbcc
    // ab
    // ab
    // a
    if ( se.size() == 2 ){
        vector<pair<int,int>> count ; 
        for(int j = 0; j < 26; j++){
            if ( cnt[j] != 0 ) count.emplace_back(cnt[j], j) ;
        }
        assert(count.size() == 2) ;
        auto first = count[0] ;
        auto last = count[1] ;
        if ( first.first < k ){
            cout << char(last.second + 'a') << endl;
            return ;
        }
        string ans = "" ;
        if ( first.first == k ){
            cout << char(first.second + 'a') ;
            for(int i = 0; i < (last.first + k - 1) / k; i++) cout << char(last.second + 'a') ;
            cout << endl;
            return ;
        }
        for(int i = 0; i < first.first - k + 1; i++){
            ans.push_back(first.second + 'a');
        }
        for(int i = 0; i < last.first; i++){
            ans.push_back(last.second + 'a') ;
        }
        cout << ans << endl;
        return ;
    }
    for(int i = 0; i < 26; i++){
        if ( cnt[i] != 0 ){
            if ( cnt[i] < k ){
                k -= cnt[i] ;
                for(int j = i + 1; j < 26; j++){
                    if ( cnt[j] < k ){
                        k -= cnt[j] ;
                    }
                    else{
                        cout << char(j + 'a') << endl;
                        return ;
                    }
                }
                assert(false);
            }
            break; 
        }
    }
    bool first = true ;
    string ans = "" ;
    for(int i = 0; i < 26; i++){
        if ( cnt[i] != 0 && first ){
            for(int j = 0; j < cnt[i] - k + 1; j++) ans.push_back(i + 'a') ;
            first = false;
        }
        else if ( cnt[i] != 0 ){
            for(int j = 0; j < cnt[i]; j++) ans.push_back(i + 'a') ;
        }
    }
    cout << ans << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}