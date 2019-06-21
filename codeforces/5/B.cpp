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
    string x ; 
    vector<string> v ; 
    int nax = 0 ; 
    while(getline(cin,x)){
    	nax = max(nax,(int)x.size());
    	v.push_back(x);
    }
    for(int i=0;i<nax+2;i++){
    	cout << '*' ; 
    }
    cout << endl;
    bool dir = 1 ; 
    for(string &s : v){
    	int n = (int)s.size() ; 
    	cout << '*' ; 
    	cout << setw(nax) ; 
    	if ( nax % 2 != n % 2 ){
    		if ( dir ){
    			int c = (nax - n) / 2 ;
    			int cc = (nax - n+1) / 2 ; 
    			string sp(c,' ');
    			string sp2(cc,' ');
    			s = sp + s + sp2 ; 
    			cout << s ; 
    			dir = !dir ; 
    		}
    		else{
    			int c = (nax - n) / 2 ;
    			int cc = (nax - n+1) / 2 ; 
    			string sp(c,' ');
    			string sp2(cc,' ');
    			s = sp2 + s + sp ; 
    			cout << s ; 
    			dir = !dir ; 
    		}
    	}
    	else{
    		int c = (nax - n) / 2 ;
    		string sp(c,' ');
    		s = sp + s + sp ; 
    		cout << s ;
    	}
    	cout << '*' ; 
    	cout << endl;
    }
    for(int i=0;i<nax+2;i++){
    	cout << '*' ; 
    }
    cout << endl;
    return 0 ;
}
