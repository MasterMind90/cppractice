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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
bool isPre(string a, string b){
    int n = (int) a.size() ;
    int m = (int) b.size() ; 
    if ( n > m ) return false ;
    int i , j ; 
    for(i = 0, j = 0; i < m && j < n; i++, j++){
        if ( a[i] != b[j] ) break ; 
    }
    if ( j == n ) return true ; 
    return false ;
}
bool isSuf(string a, string b){
    int n = (int) a.size() ;
    int m = (int) b.size() ; 
    if ( n > m ) return false ;
    int i , j ; 
    for(i = n - 1, j = m - 1; i >= 0 && j >= 0; i--, j--){
        if ( a[i] != b[j] ) break;
    }
    if ( i == -1 ) return true ; 
    return false ;
}
bool comp(string a, string b){
    return a.size() < b.size() ;
}
int main(){
    fastio
    int n ;
    cin >> n ; 
    int t = 2 * n - 2 ;
    vector<string> v[n] ;
    vector<string> sub(t) ;
    for(int i = 0; i < t; i++){
        string x ;
        cin >> x ;
        sub[i] = x ;
        v[(int)x.size()].push_back(x) ;
    }
    auto check = [&](string x){
        set<string> s ; 
        for(int i = 0; i < t; i++){
            if ( isPre(sub[i], x) ) {
                s.insert(sub[i]) ;
            }
            else if ( not isSuf(sub[i], x) ) return false ;
        }
        if ( (int)s.size() == (2 * n - 2) / 2 ) return true ;
        return false ;
    };
    string str = v[n - 1][0] + v[1][0] ; 
    set<string> s ;
    debug() << imie(str) ; 
    if ( check(str) ){
        debug() << imie(str) ; 
        for(int i = 0; i < t; i++){
            if ( isPre(sub[i], str) && s.find(sub[i]) == s.end() ){
                s.insert(sub[i]) ;
                cout << 'P' ; 
            }
            else cout << 'S' ; 
        }
        cout << endl;
        return 0 ;
    }
    s.clear() ;
    str = v[n - 1][0] + v[1][1] ; 
    debug() << imie(str) ; 
    if ( check(str) ){
        debug() << imie(str) ; 
        for(int i = 0; i < t; i++){
            if ( isPre(sub[i], str) && s.find(sub[i]) == s.end() ){
                s.insert(sub[i]) ;
                cout << 'P' ; 
            }
            else cout << 'S' ; 
        }
        cout << endl;
        return 0 ;
    }
    s.clear() ;
    str = v[n - 1][1] + v[1][0] ; 
    debug() << imie(str) ; 
    if ( check(str) ){
        debug() << imie(str) ; 
        for(int i = 0; i < t; i++){
            if ( isPre(sub[i], str) && s.find(sub[i]) == s.end() ){
                s.insert(sub[i]) ;
                cout << 'P' ; 
            }
            else cout << 'S' ; 
        }
        cout << endl;
        return 0 ;
    }
    s.clear() ;
    str = v[n - 1][1] + v[1][1] ; 
    debug() << imie(str) ; 
    if ( check(str) ){
        debug() << imie(str) ; 
        for(int i = 0; i < t; i++){
            if ( isPre(sub[i], str) && s.find(sub[i]) == s.end() ){
                s.insert(sub[i]) ;
                cout << 'P' ; 
            }
            else cout << 'S' ; 
        }
        cout << endl;
        return 0 ;
    }
    return 0 ; 
}