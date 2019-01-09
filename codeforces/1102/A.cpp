#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n ;
    cin >> n ;
    long long ans = (n*(n+1LL))/2LL;
    if ( ans % 2LL == 0 ) {
        cout << 0 << endl;
    }
    else cout << 1 << endl;
    return 0 ;
}
