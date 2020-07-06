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
int fix(int x){
    return ( x % MOD + MOD ) % MOD ;
}
signed main(){
    debug() << imie(fix(-40)) ; 
    fastio
    int n , k ;
    cin >> n >> k ;
    vector<int> pos , neg ;
    for(int i = 0; i < n; i++){
        int x ;
        cin >> x; 
        if ( x <= 0 ){
            neg.emplace_back(-x) ;
        }
        else pos.emplace_back(x) ;
    }
    int A = (int)pos.size() ;
    int B = (int)neg.size() ;
    sort(pos.rbegin(), pos.rend()) ;
    sort(neg.rbegin(), neg.rend()) ;
    debug() << imie(pos) ; 
    debug() << imie(neg) ;
    if ( k == n ) {
        int ans = 1;
        for(int i = 0; i < A; i++){
            ans *= pos[i] ;
            ans = fix(ans) ;
        }
        for(int i = 0; i < B; i++){
            ans *= -neg[i] ;
            ans = fix(ans) ;
        }
        cout << ans << endl ;
        return 0 ;
    }
    if ( pos.empty() ) {
        if ( k & 1 ) {
            int ans = 1;
            for(int i = 0; i < k; i++){
                ans *= neg[B - i - 1] ;
                ans = fix(ans) ;
            }
            ans = fix(-ans) ;
            cout << ans << endl ;
        }
        else{
            int ans = 1;
            for(int i = 0; i < k; i++){
                ans *= neg[i] ;
                ans = fix(ans) ;
            }
            cout << ans << endl ;
        }
        return 0 ;
    }
    reverse(pos.begin(), pos.end()) ;
    reverse(neg.begin(), neg.end()) ;
    int ans = 1;
    if ( k & 1 ) {
        ans = pos.back() ;
        pos.pop_back() ;
        k--;
    }
    vector<int> t ;
    while((int)pos.size() > 1){
        int a = pos.back() ; pos.pop_back();
        int b = pos.back() ; pos.pop_back() ;
        t.push_back(a * b) ;
    }
    while((int)neg.size() > 1){
        int a = neg.back() ; neg.pop_back();
        int b = neg.back() ; neg.pop_back() ;
        t.push_back(a * b) ;
    }
    k /= 2 ;
    sort(t.rbegin(), t.rend()) ;
    for(int i = 0; i < k; i++){
        t[i] %= MOD ;
        ans *= t[i] ;
        ans = fix(ans) ;
    }
    cout << ans << endl; 
    // priority_queue<int> q ; 
    // for(int i = 0; i < min(k, A); i++){
    //     q.push(-pos[i]) ;
    // }
    // int remain = k - min(k, A) ;
    // if ( remain & 1 ) {
    //     q.pop() ;
    //     remain++ ;
    // }
    // priority_queue<int> ng ; 
    // for(int i = 0; i < B; i++){
    //     ng.push(neg[i]) ;
    // }
    // for(int i = 0; i < remain; i++){
    //     q.push(-ng.top());
    //     ng.pop() ;
    // }
    // while((int)q.size() > 1 && (int)ng.size() > 1){
    //     int first = -q.top() ; q.pop() ;
    //     int second = -q.top(); q.pop() ;
    //     int a = ng.top() ; ng.pop() ;
    //     int b = ng.top() ; ng.pop() ;
    //     debug() << imie(first) imie(second) imie(a) imie(b) ;
    //     if ( a * b > first * second ) { // equal 
    //         q.push(-a) ; 
    //         q.push(-b) ;
    //     }
    //     else break ;
    // }
    // int ans = 1;
    // while(not q.empty()){
    //     ans *= -q.top() ; q.pop() ;
    //     ans = fix(ans) ;
    // }
    // cout << ans << endl ;

    // vector<int> positive(A + 1, 1) ;
    // vector<int> negative(B + 1, 1) ;
    // for(int i = 0; i < A; i++){
    //     positive[i + 1] = positive[i] * pos[i] ;
    //     positive[i + 1] = fix(positive[i + 1]) ;
    // }
    // for(int i = 0; i < B; i++){
    //     negative[i + 1] = negative[i] * neg[i] ;
    //     negative[i + 1] = fix(negative[i + 1]) ;
    // }
    // int ans = -INF ;
    // for(int i = 0; i < B + 1; i += 2){
    //     int cur = negative[i] ;
    //     int rem = k - i ;
    //     if ( rem >= 0 && rem < A + 1 ){
    //         ans = max(ans, cur * positive[rem]) ;
    //         ans = fix(ans) ;
    //     }
    // }
    // cout << fix(ans) << endl ;
    return 0; 
}