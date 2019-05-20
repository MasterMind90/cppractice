#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) , c(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
    }
    for(int i=0;i<n;i++){
        cin >> c[i] ;
    }
    int ans = -1e9 + 5 ;
    for(int i=0;i<(1<<n);i++){
        int x = 0 , y = 0 ;
        for(int j=0;j<n;j++){
            if ( (1<<j) & i ){
                x+=v[j] ;
                y+=c[j] ;
            }
        }
        ans = max(ans,x-y) ;
    }
    cout << ans << endl;


    return 0;
}
