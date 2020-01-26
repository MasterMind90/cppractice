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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    int n ;
    cin >> n ; 
    string a , b ; 
    cin >> a >> b ; 
    vector<int> ba , ab ; 
    for(int i = 0; i < n; i++){
        if ( a[i] == 'b' && b[i] == 'a' ) ba.push_back(i) ;
        else if ( a[i] == 'a' && b[i] == 'b' ) ab.push_back(i) ;
    }
    vector<pair<int,int> > ans ; 
    while((int)ba.size() > 1){
        int first = ba.back() ; 
        ba.pop_back() ; 
        int second = ba.back() ; 
        ba.pop_back() ;
        ans.push_back(make_pair(first, second));
    }
    while((int)ab.size() > 1){
        int first = ab.back() ; 
        ab.pop_back() ; 
        int second = ab.back() ; 
        ab.pop_back() ;
        ans.push_back(make_pair(first, second));
    }
    if ( (int)ba.size() == 1 && (int) ab.size() == 1 ){
        int first = ba.back() ;
        int second = ab.back() ;
        ans.push_back(make_pair(second, second)) ;
        ans.push_back(make_pair(second, first));
    }
    else if ( (int)ba.size() == 1 || (int) ab.size() == 1){
        cout << -1 << endl;
        return 0 ; 
    }
    cout << (int) ans.size() << endl;
    for(auto &p : ans){
        cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }
    return 0; 
}
/*
(b , a) , (b , a) , (b , a), (b , a) 

(a , b) , (a , b) 
*/