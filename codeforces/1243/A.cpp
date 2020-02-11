#include <bits/stdc++.h>

using namespace std;

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        vector<int> v(n) ;
        for(int i = 0; i < n; i++){
            cin >> v[i] ;
        }
        sort(v.begin(), v.end()) ;
        int ans = 0 ;
        for(int square = 1; square <= 1000; square++){
            int index = lower_bound(v.begin(), v.end(), square) - v.begin() ;
            int cnt = n - index ;
            if ( cnt >= square ){
                ans = square ;
            }
        }
        cout << ans << endl;
    }
    return 0 ;
}
