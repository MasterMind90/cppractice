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
    cout << dfs(0,0,0) << endl;

    return 0 ;
}
