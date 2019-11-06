#include <bits/stdc++.h>

using namespace std;

string a , b ;
long long n , m ;
const long long N = 3e3 + 10 ;
long long dp[N][N] ;
long long dfs(long long x, long long y){
    if ( x >= n ) return 0 ;
    if ( y >= m ) return 0 ;
    if ( dp[x][y] != -1 ) return dp[x][y] ;
    long long choice1 = 0 ;
    long long choice2 = 0 ;
    long long choice3 = 0 ;
    if ( a[x] == b[y] ){
        choice1 = 1 + dfs(x + 1, y + 1) ;
    }
    else {
        choice2 = dfs(x + 1, y) ;
        choice3 = dfs(x, y + 1) ;
    }
    return dp[x][y] = max({choice1, choice2, choice3});
}
string ans = "" ;
void build(long long x, long long y){
    if ( x >= n ) return ;
    if ( y >= m ) return ;
    //if ( dp[x][y] != -1 ) return dp[x][y] ;
    long long choice1 = 0 ;
    long long choice2 = 0 ;
    long long choice3 = 0 ;
    if ( a[x] == b[y] ){
        choice1 = 1 + dfs(x + 1, y + 1) ;
    }
    else {
        choice2 = dfs(x + 1, y) ;
        choice3 = dfs(x, y + 1) ;
    }
    long long optimal = dfs(x, y) ;

    if ( optimal == choice2 ){

        build(x + 1, y) ;
    }
    else if ( optimal == choice3 ) {

        build(x, y + 1) ;
    }
    else if (optimal == choice1 ){
        ans += a[x];
        build(x + 1, y + 1) ;
    }

}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    memset(dp, -1, sizeof dp) ;
    cin >> a >> b ;
    n = (long long) a.size() ;
    m = (long long) b.size() ;
    dfs(0, 0) ;
    build(0, 0) ;
    cout << ans << endl;
    return 0 ;
}
