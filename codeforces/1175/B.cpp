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
using ll = long long ;
const ll lim = 4294967295LL ;
bool check(ll cur){
    if ( cur > lim ) return true ;
    return false ;
}
int main(){
    int n ;
    cin >> n ;
    stack<ll> s ;
    ll cur = 0 ;
    for(int i=0;i<n;i++){
        string x ;
        cin >> x ;
        if ( x == "add" ){
            if ( s.empty() ){
                cur++;
                if ( check(cur) ){
                    cout << "OVERFLOW!!!" << endl;
                    return 0 ;
                }
            }
            else{
                ll top = s.top() ;
                if ( top == -1 ){
                    cout << "OVERFLOW!!!" << endl;
                    return 0 ;
                }
                else{
                    cur+=top ;
                    if ( check(cur) ){
                        cout << "OVERFLOW!!!" << endl;
                        return 0 ;
                    }
                }
            }
        }
        else if ( x == "for" ){
            ll c ;
            cin >> c ;
            ll top = s.empty() ? 1 : s.top() ;
            if ( top == -1 ){
                s.push(-1) ;
            }
            else{
                if ( check(top*c) ){
                    s.push(-1) ;
                }
                else{
                    s.push(top*c) ;
                }
            }
        }
        else{
            s.pop();
        }
        debug() << imie(cur) ;
    }
    cout << cur << endl;
    return 0 ;
}
