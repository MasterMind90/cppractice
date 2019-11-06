#include <bits/stdc++.h>
using namespace std;
int main(){
	int n ; 
	cin >> n ; 
	if ( n % 2 == 0 ){
		cout << fixed << setprecision(12) << 0.5 << endl;
	}
	else{
		double ans = (n / 2 + 1) / (double) n ; 
		cout << fixed << setprecision(12) << ans << endl;
	}
	return 0 ; 
}