#include <bits/stdc++.h>
using namespace std;

int main(){
	int n ; 
	cin >> n ;
	vector<int> v(n) ; 
	for(int &c : v){
		cin >> c ; 
	}
	sort(v.begin(),v.end());
	int nax = 0 ; 
	for(int i=0;i<n;i++){
		int index = upper_bound(v.begin(),v.end(),v[i]+5) - v.begin() ; 
		nax = max(index-i,nax);
	}
	cout << nax << endl;

	return 0 ; 
}