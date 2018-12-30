#include <bits/stdc++.h>
using namespace std;

int main(){
    int y , b , r ;
    cin >> y >> b >> r ;
    for(int i=y;;i--){
        if ( i+1 <= b && i+2 <= r ){
            cout << i+(i+1)+(i+2) << endl;
            return 0 ;
        }
    }

    return 0 ;
}
