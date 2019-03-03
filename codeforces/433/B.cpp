#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n,0);
    vector<long long> sum(n+1,0);
    vector<long long> sorted(n+1,0);
    for(int i=1;i<=n;i++){
        long long x ;
        cin >> x ;
        v[i-1] = x ;
        sum[i] = sum[i-1] + x ;
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        sorted[i] = sorted[i-1] + v[i-1];
    }
    int q;
    cin >> q ;
    while(q--){
        int t , a , b ;
        cin >> t >> a >> b ;
        if ( t == 1 ){
            cout << sum[b] - sum[a-1] << endl;
        }
        else cout << sorted[b] - sorted[a-1] << endl;
    }
    return 0 ;
}
