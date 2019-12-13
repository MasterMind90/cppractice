#include <bits/stdc++.h>
using namespace std;
using ll = long long ; 
int main(){
  ll a , b ; 
  cin >> a >> b ; 
  ll ans = a + b ; 
  if ( ans & 1 ) puts("IMPOSSIBLE"); 
  else cout << ans / 2LL << endl;
  return 0 ; 
}