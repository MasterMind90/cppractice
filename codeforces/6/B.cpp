#include <bits/stdc++.h>
using namespace std;
char g[105][105];
bool vis[105][105];
int n , m ;
char c ;
int main(){
    cin >> n >> m >> c ;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            vis[i][j] = false;
            if ( i == 0 || i == n+1 || j == 0 || j == m+1 ){
                g[i][j] = '.';
            }
            else{
                cin >> g[i][j];
            }
        }
    }
    set<char> ss ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if ( g[i][j] == c ){
                if ( g[i-1][j] != c && g[i-1][j] != '.' && !vis[i-1][j] ){
                    ss.insert(g[i-1][j]);
                }
                if ( g[i+1][j] != c && g[i+1][j] != '.' && !vis[i+1][j] ){
                    ss.insert(g[i+1][j]);
                }
                if ( g[i][j+1] != c && g[i][j+1] != '.' && !vis[i][j+1] ){
                    ss.insert(g[i][j+1]);
                }
                if ( g[i][j-1] != c && g[i][j-1] != '.' && !vis[i][j-1] ){
                    ss.insert(g[i][j-1]);
                }
            }
        }
    }
    cout << ss.size() << endl;


    return 0 ;
}
