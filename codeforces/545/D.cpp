#include <bits/stdc++.h>

using namespace std;

int main(){
	long long  n ; 
	cin >> n ; 
	vector<long long > v(n) ; 
	for(long long  i = 0 ; i < n; i++){
		cin >> v[i] ; 
	}
	sort(v.begin() ,v.end()) ; 

	long long  cur = 0 ; 
	long long  cnt = 0 ; 
	for(long long  i = 0 ; i < n; i++){
		if ( cur <= v[i] ) {
			cur += v[i] ; 
			cnt++ ; 
		}
	}
	cout << cnt << endl;
	return 0 ; 
}