#include <bits/stdc++.h>
using namespace std;

int main(){
    int x , y , z ; 
    cin >> x >> y >> z ;
    int a , b , c ; 
    cin >> a >> b >> c ;
    a = a-x;
    if ( a < 0 ) {
        cout << "NO" << endl;
        return 0 ; 
    }
    int AB = a+b ; 
    AB-=y;
    if ( AB < 0 ) {
        cout << "NO" << endl;
        return 0 ; 
    }
    int ABC = AB+c;
    ABC-=z;
    if ( ABC < 0 ) {
        cout << "NO" << endl;
        return 0 ; 
    }
    cout << "YES" << endl;

    return 0;
}
