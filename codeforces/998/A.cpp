#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    if ( n == 1 ) {
        cout << -1 << endl;
        return 0 ;
    }
    vector<int> v(n) ;
    int Min = 1e5 ;
    int index = 0 ;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if ( v[i] < Min ) {
            Min = v[i];
            index = i ;
        }
    }
    sort(v.begin(),v.end());
    if ( n == 2 ) {
        if ( v[0] == v[1] ) {
            cout << -1 << endl;
            return 0 ;
        }
    }
    cout << 1 << endl;
    cout << index+1 << endl;
    return 0 ;
}
