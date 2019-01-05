#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n ;
    cin >> n ;
    long long w = 1LL, h = 1LL ;
    if ( n == 1 ) {
        cout << w + h << endl;
        return 0 ;
    }
    for(int i=1;;i++){
        if ( i % 2 == 0 ) {
            h+=1;
        }
        else w+=1;

        if ( n <= (h*w) ){
            cout << h+w << endl;
            return 0 ;
        }
    }

    return 0 ;
}
