#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s ; 
	cin >> s;  
	int n = (int)s.size() ; 
	if ( n > 10 ){
		cout << s[0] << n - 2 << s[n - 1] << endl;
	}
	else cout << s << endl; 
}
int main(){
	int n ; 
	cin >> n ; 
	while(n--){
		solve() ; 
	}
	return 0 ; 
}