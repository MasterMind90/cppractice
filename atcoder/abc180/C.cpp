#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
 
int main(){
 
	ll n;
	cin >> n;
 
	vector <ll> v;
 
	for (ll i = 1; i * i <= n;i++)
		if(n%i == 0){
			cout << i << endl;
			if (n/i != i)
			v.push_back(n/i);		
	}
 
	reverse (v.begin(),v.end());
 
	for (auto x : v)
		cout << x << endl;
 
	return 0;
		
}