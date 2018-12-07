#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k, l, c, d, p, nl, np ;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np ;
    int L = k*l ;
    int C = c*d ;

    int cl = 0 ;
    while(true){
        if ( n*nl > L ) break ;
        L-=n*nl ;
        cl++;
    }
    int cc = 0 ;
    while(true){
        if ( C < n )break;
        C-=n;
        cc++;
    }
    int pp = 0 ;
    while(true){
        if ( np*n > p )break;
        p-=np*n;
        pp++;
    }
    int ans = min(cl,cc);
    ans = min(ans,pp);
    cout << ans << endl;
    return 0 ;
}
