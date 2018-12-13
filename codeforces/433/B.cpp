#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    vector<long long> sum(n+1);
    sum[0] = 0LL ;
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum[i+1] = sum[i] + (long long)v[i];
    }
    sort(v.begin(),v.end());
    vector<long long> u(n+1);
    u[0] = 0LL ;
    for(int i=0;i<n;i++){
        u[i+1] = u[i] + (long long)v[i];
    }
    int m ;
    cin >> m ;
    while(m--){
        int t , l , r ;
        cin >> t >> l >> r ;
        if ( t == 1 ) {
            cout << sum[r] - sum[l-1] << endl;
        }
        else{
            cout << u[r] - u[l-1] << endl;
        }
    }
    return 0 ;
}
