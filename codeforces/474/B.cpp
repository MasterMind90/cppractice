#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    vector<long long> v(n) ;
    for(long long &x : v){
        cin >> x ;
    }
    vector<long long> sum(n+1,0);
    for(int i=0;i<(int)v.size();i++){
        sum[i+1] = sum[i] ;
        sum[i+1] += v[i];
    }
    int q ;
    cin >> q ;
    while(q--){
        long long x ;
        cin >> x ;
        int index = lower_bound(sum.begin(),sum.end(),x) - sum.begin();
        cout << index << endl;
    }


    return 0 ;
}
