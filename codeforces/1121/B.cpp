#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ; 
    cin >> n ;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    map<int,int> sum ; 
    int ans = 1 ; 
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum[v[i]+v[j]]++;
            ans = max(ans,sum[v[i]+v[j]]);
        }
    }
    cout << ans << endl;
    return 0 ;
}
