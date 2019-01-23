#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    if ( n % 2 == 1 ) {
        cout << n << endl;
        for(int i=0;i<n;i++){
            cout << 1 << " " ;
        }
        cout << endl;
    }
    else{
        cout << n/2 << endl;
        for(int i=0;i<n/2;i++){
            cout << 2 << " " ;
        }
        cout << endl;
    }
    return 0 ;
}
