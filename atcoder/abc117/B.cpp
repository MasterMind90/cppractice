#include <bits/stdc++.h>
using namespace std;

int main(){
	int n ; 
	cin >> n ;
	vector<int> v(n) ; 
	for(int &x : v){
		cin >> x ; 
	}
	sort(v.rbegin(),v.rend());
	int sum = 0 ; 
	for(int i=1;i<n;i++){
		sum += v[i] ; 
	}
	if ( v[0] < sum ){
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0 ; 
}