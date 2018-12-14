#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    long long sum = 0LL ;
    for(int i=0;i<n;i++){
        long long x ;
        cin >> x ;
        sum += x ;
    }
    if ( sum % n == 0 ) {
        cout << n << endl;
    }
    else cout << n-1 << endl;

    return 0 ;
}
