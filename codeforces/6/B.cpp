#include <bits/stdc++.h>
using namespace std;
vector<int> row = { 0 , 0 , -1 , 1 } ; 
vector<int> col = { -1 , 1 , 0 , 0 } ; 
int main(){
    int n , m  ; 
    char c ; 
    cin >> n >> m >> c ; 
    char g[n+2][m+2] ; 
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            g[i][j] = '.' ; 
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> g[i][j] ; 
        }
    }
    set<char> ans ; 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if ( g[i][j] == c ){
                for(int k=0;k<4;k++){
                    if ( g[i+row[k]][j+col[k]] != '.' && g[i+row[k]][j+col[k]] != c ) ans.insert(g[i+row[k]][j+col[k]]) ; 
                }
            }
        }
    }
    cout << ans.size() << endl;
    return 0 ; 
}
