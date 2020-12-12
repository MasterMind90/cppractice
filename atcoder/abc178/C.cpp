#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7 ;
const int N = 1e6 + 10 ;
vector<int> fact(N) ;
int fast(int a, int b){
	if ( b == 0 ) return 1 ;
	if ( b == 1 ) return a ;
	int y = fast(a, b / 2) ;
	y *= y ;
	y %= MOD ;
	if ( b & 1 ) {
		y *= a ;
		y %= MOD ;
	}
	return y ;
}
int inv(int x){
	return fast(x, MOD - 2) ;
}
int nCk(int n, int k){
	int ans = fact[n] ;
	ans *= inv(fact[n - k]) ;
	ans %= MOD ;
	ans *= inv(fact[k]) ;
	ans %= MOD ;
	return ans ;
}
int fix(int x){
	return ((x % MOD) + MOD) % MOD ;
}
int S(int n){
	int ans = 0 ;
	for(int x = 2; x <= n; x++){
		int res = fix(fast(2, x) - 2) ;
		res %= MOD ;
		res *= fast(8, n - x) ;
		res %= MOD ;
		res *= nCk(n, x) ;
		res %= MOD ;
		ans += res ;
		ans %= MOD ;
	}
	return ans ;
}
signed main(){
	fact[0] = fact[1] = 1 ;
	for(int i = 2; i < N; i++){
		fact[i] = i * fact[i - 1] ;
		fact[i] %= MOD ;
	}
	int n ;
	cin >> n ;
	int ans = S(n) ;
	cout << ans << endl;
	return 0 ;
}