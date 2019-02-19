#include <bits/stdc++.h>
using namespace std;

int main(){
    int q ;
    cin >> q; 
    while(q--){
        long long n , a , b ;
        cin >> n >> a >> b ;
        long long ans = min(a*n,n/2*b+(n%2)*a);
        cout << ans << endl;
    }
    return 0 ;
}
