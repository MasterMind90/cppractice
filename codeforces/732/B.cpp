#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int> v(n) ;
    vector<int> ans(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
        ans[i] = v[i] ;
    }
    int total = 0 ;
    for(int i=1;i<n;i++){
        int x = k - (v[i]+ans[i-1]) ;
        if ( x > 0 ){
            total += x ;
            ans[i] = v[i]+x ;
        }
    }
    cout << total << endl;
    for(int i=0;i<n;i++){
        cout << ans[i] << ' ' ;
    }
    cout << endl;


    return 0 ;
}
