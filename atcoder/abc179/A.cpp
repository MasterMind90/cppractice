#include <iostream>

using namespace std;

int main(){
    string x ;
    cin >> x ;
    if ( x.back() == 's' ) {
        x.push_back('e') ;
        x.push_back('s') ;
    }
    else x.push_back('s') ;
    cout << x << endl;
    return 0 ;
}
