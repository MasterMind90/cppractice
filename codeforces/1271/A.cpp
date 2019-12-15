#include <bits/stdc++.h>

using namespace std;

using ll = long long ; 

int main(){
ll a , b , c , d , e ,f ; 
cin >> a >> b >> c >> d >> e >> f ; 

ll ans = 0 ; 
for(ll i = 0; i <= min({b, c, d}); i++){
ll cost = i * f + min((d - i),a) * e ;
ans = max(ans, cost) ; 
}
cout << ans << endl;


	return 0; 
}