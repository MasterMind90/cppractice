#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , a ;
    cin >> n >> a ;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i] ; 
    }
    int cnt = v[a] ; 
    int d = 1 ; 
    while( a - d >= 1 || a + d <= n ){
        if ( a - d >= 1 && a + d <= n ){
            if ( v[a - d] && v[a + d] ) cnt+=2;
        }
        else if ( a - d >= 1 ) cnt+= v[a - d];
        else if ( a + d <= n ) cnt+= v[a + d];
        d++;
    }
    cout << cnt << endl;
    return 0 ;
}
