#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
	
	int n;
	cin >> n;

	vector <pair <string,pair< int , int >>> city(n);
	for (int i = 0; i < n; i++){
		cin >> city[i].first >> city[i].second.first;
		city[i].second.first = -city[i].second.first ;
		city[i].second.second = i+1;
	}

	sort (city.begin(),city.end());

	for (int i = 0; i < n; i++){
		cout << city[i].second.second << endl;
	}
	return 0 ;
}