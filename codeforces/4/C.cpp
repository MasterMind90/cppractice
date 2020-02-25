#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n ;
    cin >> n ;
    map<string, int> mp ;
    for(int i = 0; i < n; i++){
        string s ;
        cin >> s ;
        if ( mp.count(s) == 0 ){
            mp[s]++ ;
            cout << "OK" << endl;
        }
        else{
            cout << s << mp[s] << endl;
            mp[s]++;
        }
    }

    return 0 ;
}
