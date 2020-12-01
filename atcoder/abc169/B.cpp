#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main(){
	int n ;
	cin >> n ; 
	vector<int> v(n) ; 
	int ans = 1; 
	bool zero = false ;
	for(int i = 0; i < n; i++){
		cin >> v[i] ;
		if ( v[i] == 0 ) {
			zero = true ; 
		}
	}
	if ( zero ) {
		cout << 0 << endl;
		return 0 ;
	}
	int limit = 1e18;
	for(int i = 0; i < n; i++){
		//v[i] * ans > 1e18
		if ( ans > limit / v[i] ){
			cout << -1 << endl;
			return 0 ; 
		}
		ans *= v[i] ;
	}
	cout << ans << endl;
	return 0 ;
}