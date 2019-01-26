#include <bits/stdc++.h>
using namespace std;

int main(){
    int q ;
    cin >> q ;
    while(q--){
        int n ;
        cin >> n ;
        string x ;
        cin >> x ;
        if ( n == 2 ) {
            if ( x[0] >= x[1] ) {
                cout << "NO" << endl;
                continue ;
            }
        }
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << x[0] << " " << x.substr(1) << endl;
    }

    return 0 ;
}
