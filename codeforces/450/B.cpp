#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x , y ;
    cin >> x >> y ;
    long long n ;
    cin >> n ;
    long long ar[7] ;
    ar[1] = x ;
    ar[2] = y ;
    for(int i=3;i<=6;i++){
        ar[i] = ar[i-1] - ar[i-2] ;
    }
    if ( n % 6 == 0 ) {
        cout << (ar[6]%1000000007+1000000007LL)%1000000007LL << endl;

        return 0 ;
    }
    cout << (ar[n%6]%1000000007+1000000007LL)%1000000007LL << endl;
    return 0 ;
}
