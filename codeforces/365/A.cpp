#include <bits/stdc++.h>
using namespace std;
int n , k ;
bool check(string s ){
    bool f[k+1] = {0};
    for(int i=0;i<s.size();i++){
        f[s[i]-'0'] = 1 ;
    }
    for(int i=0;i<=k;i++){
        if ( f[i] == 0 ) return false;
    }
    return true ;
}
int main(){

    cin >> n >>  k ;
    int ans = 0 ;
    for(int i=0;i<n;i++){
        string s ;
        cin >> s ;
        if ( check(s) ) ans++;
    }
    cout << ans << endl;

    return 0 ;
}
