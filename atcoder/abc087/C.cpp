#include <bits/stdc++.h>
using namespace std;
vector<int> g[2];
int n ;
int dfs(int x,int y,int cost){
    if ( x >=2 || y >= n ) return 0 ;
    if ( x == 1 && y == n-1 ){
        cost+=g[x][y] ;
        return cost ;
    }
    int first = dfs(x,y+1,cost+g[x][y]);
    int second = dfs(x+1,y,cost+g[x][y]);
    return max(first,second) ;
}

int main(){

    cin >> n ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        g[0].push_back(x);
    }
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        g[1].push_back(x);
    }
    cout << dfs(0,0,0) << endl;

    return 0 ;
}
