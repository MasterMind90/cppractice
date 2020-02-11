#include <bits/stdc++.h>

using namespace std;

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        vector<int> v(n) ;
        int nax = 0 ;
        for(int i = 0; i < n; i++){
            cin >> v[i] ;
            nax = max(nax, v[i]) ;
        }
        sort(v.begin(), v.end()) ;
        int ans = 0 ;
        for(int square = 1; square <= nax; square++){

            int L = 0 , R = n - 1 ;
            int ok = -1 ;
            while(L <= R){
                int mid = ( L + R ) / 2 ;
                if ( v[mid] >= square ){
                    ok = mid ;
                    R = mid - 1 ;
                }
                else {
                    L = mid + 1 ;
                }
            }
            if ( ok != -1 ){
                int cnt = n - ok ;
                if ( cnt >= square ){
                    ans = square ;
                }
            }
        }
        cout << ans << endl;
    }
    return 0 ;
}
