#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int main(){

    ll a , b ;
    cin >> a >> b ;
    if ( a < b ) {
        cout << a << endl;
        return 0 ;
    }
    ll hour = 0 ;
    ll rem = a % b ;
    a -= rem ;
    while(a >= b){
        hour += a ;
        a /= b ;
        a = a + rem ;
        rem = a % b ;
        if ( a >= b )
            a -= rem ;
    }
    hour += a ;
    cout << hour << endl;



    return 0 ;
}
