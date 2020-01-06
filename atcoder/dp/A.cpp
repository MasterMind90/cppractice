#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10 ;
int n ;
vector<int> v  ;
int dp[100010] ;
int dfs(int x){
    if ( x == n - 1 ){
        return 0 ;
    }
    if ( dp[x] != -1 ) return dp[x] ;
    int choice1 = INF ;
    int choice2 = INF ;
    if ( x + 1 < n )
        choice1 = abs(v[x] - v[x + 1]) + dfs(x + 1) ;
    if ( x + 2 < n )
        choice2 = abs(v[x] - v[x + 2]) + dfs(x + 2) ;


    return dp[x] = min(choice1, choice2) ;

}

int main(){
    memset(dp, -1, sizeof dp) ;
    cin >> n ;
    v.resize(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }

    int ans = dfs(0) ;

    cout << ans << endl;

    return 0 ;
}