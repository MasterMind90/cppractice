#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    int ans = 0 ;
    for(int square = 1; square <= 1000; square++){
        int cnt = 0 ;
        for(int j = 0; j < n; j++){
            if ( v[j] >= square ){
                cnt++ ;
            }
        }
        if ( cnt >= square ){
            ans = square ;
        }
    }
    cout << ans << endl;
}

int main(){
    int t ;
    cin >> t ;
    while(t--){
        solve() ;
    }
    return 0 ;
}
