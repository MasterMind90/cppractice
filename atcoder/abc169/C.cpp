#include <bits/stdc++.h>

using namespace std;
#define int long long
int toInt(string s = "123"){
	int ans = 0 ; 
	for(int i = 0; i < s.size(); i++){
		ans *= 10 ;
		ans += s[i] - '0' ; 
	}
	return ans ;
}
signed main(){
	int a ; 
	cin >> a ;
	string b ; 
	cin >> b ; 
	string t = b.erase(1, 1) ;
	int s = toInt(t) ; 
	cout << (a * s) / 100 << endl;
	return 0 ;
}