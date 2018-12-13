#include <bits/stdc++.h>
using namespace std;
int ar[3*100001];
int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if ( v[i] >= 1 && v[i] <= n){
            ar[v[i]]++;
        }
    }
    sort(v.begin(),v.end());
    long long ans = 0 ;
    for(int i=0;i<n;i++){
        if ( v[i] == i+1 ) continue ;
        int x = i + 1 ;
        if ( v[i] < 0 ){
            ans += (-1LL*v[i]+(long long)x);
        }
        else ans+= (long long)abs(v[i]-x);
    }
    cout << ans << endl;
    return 0 ;
}
