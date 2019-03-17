#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n , h ;
    cin >> n >> h ;
    vector<long long> v(n) ;
    for(long long &x : v){
        cin >> x ;
    }
    sort(v.begin(),v.end());
    long long ans = 0 ;
    for(int i=0;i<n;i++){
        long long t = max(1LL,h--);
        ans += v[i]*t;
    }
    cout << ans << endl;
    return 0 ;
}
