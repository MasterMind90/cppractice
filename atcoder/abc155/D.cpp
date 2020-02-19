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
    int n , k ;
    cin >> n >> k ; 
    vector<int> neg , pos ; 
    vector<int> test ; 
    for(int i = 0; i < n; i++){
        int x ;
        cin >> x ;
        if ( x < 0 ) neg.push_back(x) ; 
        else pos.push_back(x) ;
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    vector<int> t = neg ; 
    reverse(t.begin(), t.end());
    int L = -1e18 , R = 1e18 ; 
    int ans = -1; 
    while(L <= R){
        int mid = L + (R - L) / 2 ;
        int total = 0 ; 
        if ( mid < 0 ){
            for(int i = 0; i < neg.size(); i++){
                int l = 0 , r = pos.size() - 1 ; 
                int ans1 = -1 ;
                while(l <= r){
                    int index = l + (r - l) / 2 ;
                    if ( neg[i] * pos[index] <= mid ){
                        ans1 = index ; 
                        r = index - 1; 
                    }
                    else {
                        l = index + 1; 
                    }
                }
                if ( ans1 != -1 ) total += ((int)pos.size() - ans1);
            }
        }
        else{
            for(int i = 0; i < pos.size(); i++){
                int l = i + 1 , r = pos.size() - 1 ; 
                int ans1 = -1 ;
                while(l <= r){
                    int index = l + (r - l) / 2 ;
                    if ( pos[i] * pos[index] <= mid ){
                        ans1 = index ; 
                        l = index + 1 ;
                    }
                    else {
                        r = index - 1; 
                    }
                }
                if ( ans1 != -1 ) total += (ans1 - i);
            }
            for(int i = 0; i < t.size(); i++){
                int l = i + 1 , r = t.size() - 1 ; 
                int ans1 = -1 ;
                while(l <= r){
                    int index = l + (r - l) / 2 ;
                    if ( t[i] * t[index] <= mid ){
                        ans1 = index ; 
                        l = index + 1 ;
                    }
                    else {
                        r = index - 1; 
                    }
                }
                if ( ans1 != -1 ) total += (ans1 - i);
            }
            total += (int)neg.size() * (int)pos.size();
        }
        debug() << imie(mid) imie(total) ;
        if ( total < k ){
            L = mid + 1 ; 
        }
        else {
            ans = mid ; 
            R = mid - 1 ; 
        }
    }
    cout << ans << endl;
    return 0; 
}