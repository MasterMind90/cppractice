#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005 ;
int main(){
    int n ;
    cin >> n ;
    long long cnt[MAXN] = {0} ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        cnt[x]++;
    }
    long long dp[MAXN] = {0} ;
    for(int i=0;i<MAXN;i++){
        cnt[i] = i*cnt[i];
    }
    dp[1] = cnt[1] ;
    for(int i=2;i<MAXN;i++){
        dp[i] = max(dp[i-1],dp[i-2]+cnt[i]);
    }
    cout << dp[MAXN-1] << endl;


    return 0 ;
}
