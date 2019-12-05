#include <iostream>
using namespace std;

int main() {
int n ; 
cin >> n ; 
int curPolice = 0 ; 
int ans = 0 ; 
for(int i = 0; i < n; i++){
int x ; 
cin >> x ; 
if ( x > 0 ) curPolice += x ; 
else{
if ( curPolice > 0 ) {
curPolice-- ; 
}
else ans++ ; 
}
}
cout << ans << endl;
	return 0;
}