#include <bits/stdc++.h>
using namespace std;
 
long long max(long long a , long long b){
 
	if (a >= b)
		return a;
 
	else return b;
 
}
 
long long min(long long a , long long b){
 
	if (a <= b)
		return a;
 
	else return b;
 
}
 
long long absv(long long x){
	if (x >= 0)
		return x;
 
	else return -1*x;
}
 
/////////////////////// x = 1 , k = 5 , d = 3 //////////////////////////
////////// -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0  1  2  3  4  5  6  7  8  9  10 ///////////
 
int main(){
	long long x , k , d;
	cin >> x >> k >> d;
	x = abs(x) ;
	long long ok = k;
 
	if (x > 0){
 
		k -= min(k,absv(x/d));
		x -= d*min(ok,(x/d));
 
		if (k%2 == 0)
			cout << x << endl;
 
		else cout <<  min(absv(x - d),absv(x+d)) << endl;
 
 
	}
 
	else if (x < 0){
 
		k -= min(k,x/d);
		x -= d*min(ok,absv(x/d));
 
		if (k%2 == 0) cout << absv(x) << endl;
		else cout << min(absv(x - d),absv(x+d)) ;
 
 
	}
 
	else {
 
		if (k%2 == 0) cout << 0 << endl;
		else cout << d << endl;
 
	}
 
	return 0;
}