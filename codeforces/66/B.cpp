#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ; 
    cin >> n ;
    vector<int> v(n) ;
    for(int &x : v){
        cin >> x ;
    }
    int ans = 0 ; 
    for(int i=0;i<n;i++){
        int cnt = 1 ;
        for(int j=i+1;j<n;j++){
            if ( v[j] <= v[j-1] ) cnt++;
            else break;
        }
        for(int j=i-1;j>=0;j--){
            if ( v[j] <= v[j+1] ) cnt++;
            else break;
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
    return 0 ;
}
