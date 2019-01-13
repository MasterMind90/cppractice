#include <bits/stdc++.h>

using namespace std;

int main(){
    int n , s , t ;
    cin >> n >> s >> t ;
    vector<int> v(n+1) ;
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    if ( s == t ) {
        cout << 0 << endl;
    }
    else{
        int x = s ;
        int ans = 0 ;
        vis[x] = true ;
        bool f = false ;
        while( x != v[x] ){
            f = true ;
            if ( x == t ) break ;
            if ( vis[v[x]] ){
                cout << -1 << endl;
                return 0 ;
            }
            x = v[x] ;
            vis[x] = true ;
            ans++;
        }
        if ( f == false ) {
            cout << -1 << endl;
            return 0 ;
        }
        else{
            cout << ans << endl;
            return 0 ;
        }

    }
    return 0 ;
}
