#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n , v ;
    cin >> n >> v ;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int k = n-i-j ;
            if ( k >= 0 ){
                long long ans = i*10000LL + 5000LL * j + k * 1000LL;
                if ( ans == v ){
                    cout << i << ' ' << j << ' ' << k << endl;
                    return 0 ;
                }
            }
        }
    }
    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
    return 0 ;
}
