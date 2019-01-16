#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<long long> v(n+1) ;
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    vector<long long> sum(n+1);
    sum[0] = 0LL ;
    for(int i=1;i<=n;i++){
        sum[i] = v[i]+sum[i-1];
    }
    while(m--){
        long long x ;
        cin >> x ;
        int index = lower_bound(sum.begin(),sum.end(),x) - sum.begin();
        cout << index << " " << x-sum[index-1] << endl;
    }
    return 0 ;
}
