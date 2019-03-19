#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n ; 
    cin >> n ; 
    vector<long long> v(n) ; 
    for(long long &x: v){
        cin >> x;
    }
    long long first = 0 ; 
    for(long long i=0;i<n;i++){
        if ( v[i] == 1 ) first++;
        else break;
    }
    long long last = 0 ; 
    for(long long i=n-1;i>=0;i--){
        if ( v[i] == 1 ) last++;
        else break;
    }
    long long ans = first+last ; 
    long long cur = 0 ; 
    for(long long i=0;i<n;i++){
        if ( v[i] == 1 ) cur++;
        else{
            ans = max(ans,cur);
            cur = 0 ; 
        }
    }
    ans = max(cur,ans);
    cout << ans << endl;
    return 0 ; 
}
