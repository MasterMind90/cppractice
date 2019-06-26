#include <bits/stdc++.h>
using namespace std;

int main(){

    int d , n ;
    cin >> d >> n ;
    if ( n == 100 ){
        if ( d == 0 ) cout << 100 + 1 << endl;
        else if ( d == 1 ) cout << 10000 + 100 << endl;
        else cout << 1000000 + 10000 << endl;
        return 0 ;
    }
    if ( d == 0 ) cout << n << endl;
    else if ( d == 1 ) cout << n * 100 << endl;
    else cout << n * 10000 << endl;



    return 0 ;
}
