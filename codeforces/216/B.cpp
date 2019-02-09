#include <bits/stdc++.h>
using namespace std;

bool g[105][105];
bool vis[105];
int n , m ; 
bool flag = false;
int counter = 0 ; 

void dfs(int x,int p){
    counter++;
    vis[x] = true ;
    for(int i=1;i<=n;i++){
        if ( g[x][i] && !vis[i] ){
            dfs(i,x);
        }
        else if ( g[x][i] && vis[i] ){
            if ( p != i ){
                flag = true ;
            }
        }

    }
}

int main(){
    cin >> n >> m ; 
    for(int i=0;i<m;i++){
        int x , y ; 
        cin >> x >> y ; 
        g[x][y] = 1 ; 
        g[y][x] = 1 ; 
    }
    int cnt = 0 ; 
    for(int i=1;i<=n;i++){
        flag = false ;
        counter = 0 ; 
        if ( !vis[i] ){
            dfs(i,i);
            if ( flag ) {
                if ( counter % 2 == 1 ) cnt++;
            }
        }
    }
    if ( ( n - cnt ) % 2 == 1 ) cnt++;
    cout << cnt << endl;
    return 0 ; 
}
