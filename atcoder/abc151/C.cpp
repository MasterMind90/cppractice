#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    int n , m ;
    cin >> n >> m ;
    bool done[n + 1] = {0};
    int cnt[n + 1] = {0} ;

    for(int i = 0; i < m; i++){
        int p ;
        string s ;
        cin >> p >> s ;
        if ( s == "WA" ){
            if ( !done[p] ){
                cnt[p]++ ;
            }
        }
        else{
            done[p] = true ;
        }
    }
    int ans = 0 ;
    int pen = 0 ;
    for(int i = 1; i < n + 1; i++){
        if ( done[i] ) {
            ans++;
            pen += cnt[i] ;
        }
    }
    cout << ans << ' ' << pen << endl;
    return 0 ;
}
