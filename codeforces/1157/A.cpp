#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    if ( n < 10 ){
        cout << 9 << endl;
        return 0 ;
    }
    int ans = 9 ;
    while(n>=10){
        int r = n%10;
        ans += (10-r);
        n+=(10-r);
        while(n%10==0){
            n/=10;
        }
    }
    cout << ans << endl;
    return 0 ;
}