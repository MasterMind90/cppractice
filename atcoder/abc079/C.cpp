#include <bits/stdc++.h>
using namespace std;

int main(){
	string s ; 
	cin >> s ; 
	int n = 3 ; 
	for(int mask=0;mask<(1<<n);mask++){
		int ans = s[0] - '0' ; 
		for(int j=0;j<n;j++){
			if ( (1<<j) & mask ){
				ans += s[j+1]-'0' ; 
			}
			else 
				ans -= s[j+1]-'0' ; 
		}
		if ( ans == 7 ){
			cout << s[0] ; 
			for(int j=0;j<n;j++){
				if ( (1<<j) & mask ){
					cout << "+" << s[j+1] ;
				}
				else 
					cout << "-" << s[j+1] ; 
			}
			cout << "=7" << endl;
			return 0 ; 
		}
	}
	return 0 ; 
}