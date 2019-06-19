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
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; 
	int n ; 
	cin >> n ; 
	for(int i=0;i<n;i++){
		string x , y ; 
		cin >> x >> y ; 
		int cnt = 1 ; 
		vector<pair<char,int> > first ; 
		for(int j=1;j<(int)x.size();j++){
			if ( x[j] != x[j-1] ){
				first.push_back({x[j-1],cnt});
				cnt = 1 ; 
			}
			else cnt++ ; 
		}
		first.push_back({x[(int)x.size()-1],cnt});
		// do not forget the end cnt 
		cnt = 1 ; 
		vector<pair<char,int> > second ; 
		for(int j=1;j<(int)y.size();j++){
			if ( y[j] != y[j-1] ){
				second.push_back({y[j-1],cnt});
				cnt = 1 ; 
			}
			else cnt++ ; 
		}
		second.push_back({y[(int)y.size()-1],cnt});
		debug() << imie(first) ; 
		debug() << imie(second) ; 
		bool flag = true ; 
		if ( (int) first.size() != (int) second.size() ){
			cout << "NO" << endl;
			continue ; 
		}
		for(int j=0;j<(int)first.size();j++){
			if ( first[j].first == second[j].first ){
				if ( first[j].second > second[j].second ){
					flag = false ; 
					break ; 
				}
			}
			else{
				flag = false ; 
				break;
			}
		}
		if ( flag ){
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
    return 0 ;
}
