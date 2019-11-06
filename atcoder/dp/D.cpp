#include <bits/stdc++.h>

using namespace std;
const long long INF = 1e18 + 10 ;
long long n , W ;
vector<long long> w , v ;
long long dp[110][100010] ;
long long dfs(long long x, long long cur){
    if ( cur > W ) return -INF ;
    if ( x == n ){
        return 0 ;
    }
    if ( dp[x][cur] != -1 ) return dp[x][cur] ;
    long long choice1 = dfs(x + 1, cur) ;
    long long choice2 = v[x] + dfs(x + 1, cur + w[x]);
    return dp[x][cur] = max(choice1, choice2) ;
}

int main(){
    memset(dp, -1, sizeof dp) ;
    cin >> n >> W ;
    w.resize(n) ;
    v.resize(n) ;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i] ;
    }
    cout << dfs(0, 0) << endl;

    return 0 ;
}
