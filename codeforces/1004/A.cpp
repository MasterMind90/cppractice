#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n , d ;
    cin >> n >> d ;
    vector<long long> v(n) ;
    map<long long,bool> m ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
    }
    long long ans = 2 ;
    for(int i=0,j=1;j<n;i++,j++){
        long long p = v[i]+d ;
        long long p2 = v[j]-d;
        if ( p == p2 ) ans++;
        if ( p2 > p ) ans+=2 ;
    }
    cout << ans << endl;
    return 0 ;
}
