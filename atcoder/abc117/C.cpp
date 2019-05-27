#include <bits/stdc++.h>
using namespace std;

int main(){
	int n , m ; 
	cin >> n >> m ; 
	if ( n >= m ){
		cout << 0 << endl;
		return 0 ; 
	}
	vector<int> v(m) ; 
	for(int i=0;i<m;i++){
		cin >> v[i] ; 
	}
	sort(v.begin(),v.end());
	vector<int> diff ; 
	for(int i=1;i<m;i++){
		diff.push_back( abs(v[i]-v[i-1]) ) ;  
	}
	sort(diff.rbegin(),diff.rend());
	int sum = 0 ; 
	for(int i=n-1;i<(int)diff.size();i++){
		sum += diff[i] ; 
	}
	cout << sum << endl;
	return 0 ; 
}