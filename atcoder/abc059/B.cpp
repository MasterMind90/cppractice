#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
	string a , b ; 
	cin >> a >> b ; 
	int n = (int) a.size() ;
	int m = (int) b.size() ;
	if ( n > m ) {
		cout << "GREATER" << endl;
	}
	else if ( n < m ) {
		cout << "LESS" << endl;
	}
	else {
		if ( a > b ) {
			cout << "GREATER" << endl;
		}
		else if ( a < b ) {
			cout << "LESS" << endl;
		}
		else cout << "EQUAL" << endl;
	}
	return 0 ;
}