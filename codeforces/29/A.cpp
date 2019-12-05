#include <bits/stdc++.h>
using namespace std;

int main() {
int n ; 
cin >> n ; 
vector<pair<int,int> > v(n) ; 
for(int i = 0; i < n; i++){
cin >> v[i].first >> v[i].second ; 
}
for(int i = 0; i < n; i++){
int posi = v[i].first + v[i].second ; 
for(int j = i + 1; j < n; j++){
if ( v[j].first == posi && v[j].first + v[j].second == v[i].first ) return cout<< "YES" << endl, 0 ; 
}
}
cout << "NO" << endl;
	return 0;
}