#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t ;
    cin >> t ;
    while(t--){
        vector<int> v(3) ;
        for(int i = 0; i < 3; i++){
            cin >> v[i] ;
        }
        sort(v.begin(), v.end()) ;
        reverse(v.begin(), v.end()) ;
        int ans = 0 ;
        if ( v[0] ) {
            v[0]--;
            ans++;
        }
        if ( v[1] ) {
            v[1]--;
            ans++;
        }
        if ( v[2] ) {
            v[2]--;
            ans++;
        }
        if ( v[0] && v[1] ){
            v[0]--;
            v[1]--;
            ans++;
        }
        if ( v[0] && v[2] ){
            v[0]--;
            v[2]--;
            ans++;
        }
        if ( v[1] && v[2] ){
            v[1]--;
            v[2]--;
            ans++;
        }
        if ( v[0] && v[1] && v[2] ){
            ans++ ;
        }
        cout << ans << endl;


    }

    return 0 ;
}
