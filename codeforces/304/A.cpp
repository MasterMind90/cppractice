#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    int ans = 0 ;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int a = (i*i + j*j);
            double b = sqrt(a);
            double c = b - int(b);
            if ( c < 0.000001 && b <= n ) ans++;
        }
    }
    cout << ans << endl;

    return 0 ;
}
