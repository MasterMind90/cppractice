#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , x , y  ;
    cin >> n >> x >> y ;
    string s ;
    cin >> s ;
    int cnt = 0 ;
    int ans = 0 ;
    for(int i=n-1;cnt<x;i--,cnt++){
        if ( s[i] == '1' ){
            ans++;
        }
    }
    if ( s[n-y-1] == '1' ) ans--;
    else ans++;

    cout << ans << endl;

    return 0 ;
}
