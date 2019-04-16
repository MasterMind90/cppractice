#include <bits/stdc++.h>
using namespace std;

int main(){
    int ar[4] ;
    for(int i=0;i<4;i++){
        cin >> ar[i] ;
    }
    sort(ar,ar+4);

    int c = ar[3] - ar[0] ;
    int a = ar[2] - c ;
    int b = ar[0] - a ;
    cout << a << ' ' << b << ' ' << c << endl;

    return 0 ;
}
