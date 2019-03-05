#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n , k ;
    cin >> n >> k ;
    if ( n % 2 == 0 ){
        long long mid = n/2;
        if ( k <= mid ){
            cout << 1+(k-1)*2 << endl;
        }
        else{
            k = k - mid ;
            cout << 2+(k-1)*2 << endl;
        }
    }
    else{
        long long mid = n/2+1;
        if ( k <= mid ){
            cout << 1+(k-1)*2 << endl;
        }
        else{
            k = k - mid ;
            cout << 2+(k-1)*2 << endl;
        }
    }
    return 0 ;
}
