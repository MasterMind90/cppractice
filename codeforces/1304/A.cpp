#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t ;
    cin >> t ;
    while(t--){
        int x , y , a , b ;
        cin >> x >> y >> a >> b ;
        int L = 0, R = 2e9 ;
        int ans = -1;
        while(L <= R){
            int mid = L + (R - L) / 2 ;
            int posX = x + mid * a ;
            int posY = y - mid * b ;
            if ( posX == posY ){
                ans = mid ;
                break;
            }
            if ( posX > posY ){
                R = mid - 1 ;
            }
            else L = mid + 1 ;
        }
        cout << ans << endl;
    }

    return 0 ;
}
