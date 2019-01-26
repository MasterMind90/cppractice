#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , q ;
    cin >> n >> q ;
    int p[32] = {0} ;
    memset(p,0,sizeof(p));
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        for(int i=0;i<=32;i++){
            if ( x == 1<<i ) {
                p[i]++;
                break;
            }
        }
    }
    while(q--){
        int x ;
        cin >> x ;
        int ans = 0 ;
        for(int i=31;i>=0;i--){
            int mm = min(x/(1<<i),p[i]);
            ans+= mm ;
            x = x - mm*(1<<i);
        }
        if ( x == 0 ) {
            cout << ans << endl;
        }
        else cout << -1 << endl;
    }
    return 0 ;
}
