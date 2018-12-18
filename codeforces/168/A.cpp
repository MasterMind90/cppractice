#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , x , y ;
    cin >> n >> x >> y ;
    int c = ceil(y/100.0 * n);
    if ( x >= c ) {
        cout << 0 << endl;
    }
    else cout << c-x << endl;
    return 0 ;
}
