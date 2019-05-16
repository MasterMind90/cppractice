#include <bits/stdc++.h>
using namespace std;

int main(){
    int X[] = {1,-1,0, 0} ;
    int Y[] = {0, 0,1,-1} ;
    int n , m ;
    cin >> n >> m ;
    char grid[n][m] ;
    bool vis[n][m] ;
    pair<int,int> parent[n][m] ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j] ;
            vis[i][j] = false ;
        }
    }
    queue<pair<int,int> > q ;
    q.push({0,0});
    vis[0][0] = true ;
    parent[0][0] = {0,0} ;
    while(q.size()){
        auto f = q.front() ; q.pop() ;
        int x = f.first ;
        int y = f.second ;
        for(int i=0;i<4;i++){
            if ( X[i] + x >= 0 && X[i] + x < n && Y[i] + y >= 0 && Y[i] + y < m && grid[X[i]+x][Y[i]+y] == '.' && !vis[X[i]+x][Y[i]+y]){
                vis[X[i]+x][Y[i]+y] = true ;
                parent[X[i]+x][Y[i]+y] = {x,y} ;
                q.push({X[i]+x,Y[i]+y});
            }
        }
    }
    if ( !vis[n-1][m-1] ){
        cout << -1 << endl;
    }
    else{
        int white = 0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if ( grid[i][j] == '.' ) white++;
            }
        }
        pair<int,int> start = {n-1,m-1} ;
        int cnt = 0 ;
        while(start != parent[start.first][start.second] ){
            cnt++ ;
            start = parent[start.first][start.second] ;
        }
        cout << white - cnt - 1 << endl;
    }
    return 0 ;
}
