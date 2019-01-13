#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q ;
    cin >> q ;
    long long X = -1e18 , Y = -1e18 ;
    long long XX = -1e18 , YY = 1e18 ;
    while(q--){
        char t ;
        long long x , y ;
        cin >> t >> x >> y ;
        if ( y < x ) swap(x,y);
        if ( t == '+' ) {
            X = max(X,x);
            Y = max(Y,y);
        }
        else{
            if ( (X <= x && Y <= y) || (Y <= x && X <= y) ){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }

    return 0 ;
}
