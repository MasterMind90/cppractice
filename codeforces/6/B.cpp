#include <bits/stdc++.h>

using namespace std;

int main(){
    int n , m ;
    char p ;
    cin >> n >> m >> p ;
    char a[n + 2][m + 2] ;
    for(int i = 0; i < n + 2; i++){
        for(int j = 0; j < m + 2; j++){
            a[i][j] = '.' ;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j] ;
        }
    }
    set<char> s ;
    int X[] = {0, 0, 1, -1} ;
    int Y[] = {1,-1, 0,  0} ;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if ( a[i][j] == p ){
                for(int k = 0; k < 4; k++){
                    if ( a[i + X[k]][j + Y[k]] != p && a[i + X[k]][j + Y[k]] >= 'A' &&  a[i + X[k]][j + Y[k]] <= 'Z' ){
                        s.insert(a[i + X[k]][j + Y[k]]);
                    }
                }
            }
        }
    }
    cout << s.size() << endl;






    return 0 ;
}
