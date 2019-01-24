#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n);
    vector<bool> f(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int x = v[v.size()-1];
    f[0] = true ;
    for(int i=1;i<n;i++){
        if ( v[i] == v[i-1] ) continue ;
        if ( x % v[i] == 0 ) f[i] = true;
    }
    int y ;
    for(int i=n-1;i>=0;i--){
        if ( f[i] == false ) {
            y = v[i];
            break;
        }
    }
    cout << x << " " << y << endl;
    return 0 ;
}
