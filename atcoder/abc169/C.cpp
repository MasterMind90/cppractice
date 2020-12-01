#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main(){
	int a ; 
	cin >> a ;
	string b ; 
	cin >> b ; 
	string t = b.erase(1, 1) ;
	int s = stoi(t) ; 
	cout << (a * s) / 100 << endl;
	return 0 ;
}