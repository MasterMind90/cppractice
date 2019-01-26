#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n ;
    cin >> n ;
    while(n--){
        long long k , x ;
        cin >> k >> x ;
        k--;
        long long ans = k*9LL+x ;
        cout << ans << endl;
    }
    return 0 ;
}
