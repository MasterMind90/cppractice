#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    char grid[n+5][n+5] ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> grid[i][j] ;
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=2;j<=n-1;j++){
            if ( grid[i][j] == '.' ){
                if ( grid[i+1][j] == '.' ){
                    if ( grid[i+1][j+1] == '.' ){
                        if ( grid[i+1][j-1] == '.' ){
                            if ( grid[i+2][j] == '.' ){
                                grid[i][j] = '#' ;
                                grid[i+1][j] = '#' ;
                                grid[i+1][j+1] = '#' ;
                                grid[i+1][j-1] = '#' ;
                                grid[i+2][j] = '#' ;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if ( grid[i][j] == '.' ){
                cout << "NO" << endl;
                return 0 ;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
