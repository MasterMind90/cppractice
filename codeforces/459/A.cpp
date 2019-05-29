#include <bits/stdc++.h>
using namespace std;

int main(){
	int x , y , a , b ; 
	cin >> x >> y >> a >> b ; 
	if ( x > a ){
		swap(x,a);
		swap(y,b) ; 
	}
	if ( x != a && y != b ){
		if ( abs(x - a) == abs(y - b) ){
			cout << x << ' ' << b << ' ' << a << ' ' << y << endl;
			return 0 ; 
		}
		else cout << -1 << endl;
	}
	else if ( x == a ){
		int len = abs(y-b) ; 
		cout << x + len << ' ' << y << ' ' << x + len << ' ' << b << endl;
	}
	else if ( y == b ){
		int len = abs(x-a) ; 
		cout << x << ' ' << y+len << ' ' << a << ' ' << b+len << endl;
	}
	else{
		cout << -1 << endl;
	}
	return 0 ; 
}
