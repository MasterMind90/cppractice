#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    int fe = 0 ;
    int fo = 0 ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        if ( x & 1 ) fo++;
        else fe++;
    }
    int so = 0 ;
    int se = 0 ;
    for(int i=0;i<m;i++){
        int x ;
        cin >> x ;
        if ( x & 1 ) so++;
        else se++;
    }
    int ans = min(fo,se) + min(fe,so) ;
    cout << ans << endl;
    return 0 ;
}
