#include <bits/stdc++.h>
using namespace std;
int main(){
	int n , m ; 
	cin >> n >> m ; 
	int r , c ; 
	cin >> r >> c ; 
	int ans = n * m - r * m - (n - r)*c; 
	cout << ans << endl;
	return 0; 
}