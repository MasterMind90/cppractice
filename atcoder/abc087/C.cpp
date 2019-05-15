#include <bits/stdc++.h>
using namespace std;
int n ;
vector<int> v[2] ;
int dfs(int x,int y,int sum){
    sum += v[x][y] ;
    if ( x == 1 && y == n-1 ){
        return sum ;
    }
    int right = 0, left = 0 ;
    if ( y + 1 < n )
        right = dfs(x,y+1,sum);
    if ( x + 1 < 2 )
        left = dfs(x+1,y,sum);
    return max(right,left);
}
int main(){
    cin >> n ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        v[0].push_back(x);
    }
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        v[1].push_back(x);
    }
    vector<int> sum1(n+1);
    vector<int> sum2(n+1);
    sum1[0] = 0 ;
    sum2[0] = 0 ;
    for(int i=1;i<=n;i++){
        sum1[i] = sum1[i-1] + v[0][i-1];
        sum2[i] = sum2[i-1] + v[1][i-1];
    }
    int ans = 0 ;
    for(int i=0;i<n;i++){
        int res = sum1[i+1] + sum2[n] - sum2[i] ;
        ans = max(ans,res);
    }
    cout << ans << endl;
    return 0 ;
}
