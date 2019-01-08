#include <bits/stdc++.h>

using namespace std;
int main(){
    int n , m ;
    cin >> n >> m ;
    vector<int> v(n);
    vector<int> cnt(n);
    for(int i=0;i<n;i++){
        cnt[i] = 0 ;
    }
    for(int i=0;i<v.size();i++){
        cin >> v[i];
        if ( v[i] == 1 ) {
            int l = i-m+1 ;
            if ( l < 0 ) l = 0 ;
            int r = i+m-1;
            if ( r >= n ) r = n-1;
            for(int j=l;j<=r;j++) cnt[j]++;
        }
    }
    for(int i=0;i<n;i++){
        if ( cnt[i] == 0 ) {
            cout << -1 << endl;
            return 0 ;
        }
    }
    int ans = 0 ;
    for(int i=0;i<n;i++){
        if ( v[i] == 1 ) {
            int l = i-m+1 ;
            if ( l < 0 ) l = 0 ;
            int r = i+m-1;
            if ( r >= n ) r = n-1;
            bool flag = false ;
            for(int j=l;j<=r;j++){
                if ( cnt[j] == 1 ) {
                    ans++;
                    flag = true ;
                    break;
                }
            }
            if ( flag == false ){
                for(int j=l;j<=r;j++){
                    cnt[j]--;
                }
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}
