#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10 ;
long long n , W ;
vector<long long> v , w ;
long long dp[110][MAXN] ;
long long dfs(long long x,long long curr){
    if ( x == n ){
        return 0 ;
    }
    if ( dp[x][curr] != -1 ) return dp[x][curr] ;
    long long choice1 = 0 + dfs(x+1,curr) ;
    long long choice2 = -1e18 ;
    if ( curr + w[x] <= W ){
        choice2 = v[x] + dfs(x+1,curr+w[x]) ;
    }
    long long ans = max(choice1,choice2);
    dp[x][curr] = ans ;
    return ans ;
}


int main(){
    memset(dp,-1,sizeof dp);
    cin >> n >> W ;
    v.resize(n) ;
    w.resize(n) ;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i] ;
    }
    cout << dfs(0,0) << endl;
    return 0 ;
}

