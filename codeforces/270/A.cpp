#include <iostream>
using namespace std;
int T,a;
int main(){
    cin >> T;
    while(T--){
       cin >> a ;
       int sides = 360/(180-a) ;
       if ( (180-a)*sides == 360 ) cout << "YES" << endl;
       else cout << "NO" << endl;
    }
    return 0;
}
