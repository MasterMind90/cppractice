#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , m , b ;
    cin >> n >> m >> b ;
    int nax1 = 1e9 ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        if ( x < nax1 ){
            nax1 = x ;
        }
    }
    int nax2 = -1e9 ;
    for(int i=0;i<m;i++){
        int x ;
        cin >> x ;
        if ( x > nax2 ){
            nax2 = x ;
        }
    }
    int t = b/nax1 ;

    int ans = t * nax2 + (b%nax1) ;

    cout << max(b,ans) << endl;

    return 0 ;
}
