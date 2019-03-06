#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 5005 ;
int section[N] ;
int main(){
	int n , q ;
	cin >> n >> q ;
	vector<pair<int,int> > v(q) ;
	for(int i=0;i<q;i++){
		cin >> v[i].fi >> v[i].se ;
		for(int j=v[i].fi;j<=v[i].se;j++){
			section[j]++;
		}
	}
	int nax = 0 ;
	for(int i=0;i<q;i++){
		for(int j=v[i].fi;j<=v[i].se;j++){
			section[j]--;
		}
		vector<int> ones(n+1,0);
		int cnt = 0 ;
		for(int j=1;j<=n;j++){
			if ( section[j] ) cnt++;
			if ( section[j] == 1 ) {
				ones[j]++;
			}
			ones[j]+=ones[j-1];
		}
		for(int j=0;j<q;j++){
			if ( i == j ) continue ;
			nax = max(nax,cnt-(ones[v[j].se] - ones[v[j].fi - 1]));
		}
		for(int j=v[i].fi;j<=v[i].se;j++){
			section[j]++;
		}
	}
	cout << nax << endl;
	return 0 ;
}
