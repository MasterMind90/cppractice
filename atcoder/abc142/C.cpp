#include <bits/stdc++.h>
using namespace std;
int main(){
	int n ;
	cin >> n ;
	vector<int> v(n + 1) ;
	for(int i = 1; i <= n; i++){
        int x ;
        cin >> x ;
        v[x] = i ;
	}
	for(int i = 1; i <= n; i++){
        cout << v[i] << ' ' ;
	}
	return 0 ;
}
