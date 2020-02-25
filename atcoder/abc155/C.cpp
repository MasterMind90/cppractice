#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n ;
    cin >> n ;
    vector<string> v ;
    for(int i = 0; i < n; i++){
        string s ;
        cin >> s ;
        v.push_back(s) ;
    }
    sort(v.begin(), v.end()) ;
    int total = 0 ;
    vector<pair<string,int> > vv ;
    for(int i = 0; i < n; i++){
        int L = i + 1, R = n - 1 ;
        int ans = -1 ;
        while(L <= R){
            int mid = (L + R) / 2 ;
            if ( v[mid] > v[i] ){
                ans = mid ;
                R = mid - 1 ;
            }
            else L = mid + 1 ;
        }
        if ( ans == -1 ) ans = n ;

        if ( ans - i >= total ){
            total = ans - i ;
            vv.push_back(make_pair(v[i], total)) ;
        }
    }
    int cnt = 0 ;
    for(auto p : vv){
        if ( p.second == total ){
            cout << p.first << endl;
        }
    }
    return 0 ;
}
