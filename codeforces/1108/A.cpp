#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    for(int i=0;i<n;i++){
        int x,y,l,r;
        cin >> x >> y >> l >> r ;
        cout << x << " " ;
        if ( x == l ) cout << r << endl;
        else cout << l << endl;
    }


    return 0 ;
}
