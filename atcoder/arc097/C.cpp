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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

int main(){
    fastio
    string s ; 
    cin >> s ; 
    int k ; 
    cin >> k ; 
    int n = (int) s.size() ; 
    set<string> ss ; 
    for(int i=0;i<n;i++){
    	ss.insert(s.substr(i,1));
    }
    for(int i=0;i+1<n;i++){
    	ss.insert(s.substr(i,2));
    }
    for(int i=0;i+2<n;i++){
    	ss.insert(s.substr(i,3));
    }
    for(int i=0;i+3<n;i++){
    	ss.insert(s.substr(i,4));
    }
    for(int i=0;i+4<n;i++){
    	ss.insert(s.substr(i,5));
    }
    vector<string> v(ss.begin(),ss.end()) ; 
    cout << v[k-1] << endl;
    debug() << imie(ss) ; 
    return 0 ;
}
