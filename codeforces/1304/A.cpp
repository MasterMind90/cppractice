#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int t ;
    cin >> t ;
    while(t--){
        int x , y , a , b ;
        cin >> x >> y >> a >> b ;
        int L = 0, R = 1e9 ;
        int ans = -1 ;
        while(L <= R){
            int sec = ( L + R ) / 2 ;
            int posA = x + sec * a ;
            int posB = y - sec * b ;
            if ( posA == posB ){
                ans = sec ;
                break;
            }
            if ( posA > posB ){
                R = sec - 1 ;
            }
            else L = sec + 1 ;
        }
        cout << ans << endl;
    }

    return 0 ;
}

