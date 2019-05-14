#include <bits/stdc++.h>
using namespace std;

int main(){
    string a , b ;
    cin >> a >> b ;
    string c = a + b ;
    stringstream ss ;
    ss << c ;
    int x ;
    ss >> x ;
    double z = sqrt(x);

    double fraction = z - (int) z ;

    if ( fraction < 1e-6 ){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    return 0 ;
}
