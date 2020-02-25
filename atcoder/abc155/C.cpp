#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    map<string,int> mp ;
    int n ;
    cin >> n ;
    int cnt = 0 ;
    for(int i = 0; i < n; i++){
        string x ;
        cin >> x ;
        mp[x]++ ;
        cnt = max(cnt, mp[x]) ;
    }
    for(auto p : mp){
        if ( p.second == cnt )
            cout << p.first << endl;
    }
    return 0 ;
}
