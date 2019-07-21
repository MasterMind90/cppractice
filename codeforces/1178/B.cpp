#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    int n = (int) s.size() ;
    vector<long long> left(n+1) ;
    for(int i=1;i<n;i++){
        left[i] = left[i-1] + (s[i] == 'v' && s[i-1] == 'v') ;
    }
    long long ans = 0 ;
    for(int i=0;i<n;i++){
        if ( s[i] == 'o' ) ans += (left[i] * (left[n-1]-left[i]));
    }
    cout << ans << endl;
    return 0 ;
}
