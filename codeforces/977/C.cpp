#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
    }
    sort(v.begin(),v.end());
    if ( k == 0 && v[0] == 1 ) {
        cout << -1 << endl;
        return 0 ;
    }
    if ( k == 0 && v[0] != 1 ) {
        cout << 1 << endl;
        return 0 ;
    }
    k--;
    if ( k == n-1 ) {
        cout << v[k] << endl;
        return 0 ;
    }
    if ( v[k] == v[k+1] ){
        cout << -1 << endl;
        return 0 ;
    }
    cout << v[k] << endl;
    return 0 ;
}
