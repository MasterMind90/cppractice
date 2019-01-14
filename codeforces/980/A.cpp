#include <bits/stdc++.h>
using namespace std;

int main(){
    string x ;
    cin >> x ;
    int l = 0 ;
    int p = 0 ;
    for(int i=0;i<x.size();i++){
        if ( x[i] == 'o' ) p++;
        else l++;
    }
    if ( p == 0 ) {
        cout << "YES" << endl;
        return 0 ;
    }
    if ( l % p == 0 ) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

    return 0 ;
}
