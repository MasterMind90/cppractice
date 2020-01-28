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
    bool flag[26] = {0} ;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if ( a[i][j] == p ){
                if ( a[i - 1][j] != p && a[i - 1][j] >= 'A' && a[i - 1][j] <= 'Z' ){
                    flag[a[i - 1][j] - 'A'] = true ;
                }
                if ( a[i + 1][j] != p && a[i + 1][j] >= 'A' && a[i + 1][j] <= 'Z' ){
                    flag[a[i + 1][j] - 'A'] = true ;
                }
                if ( a[i][j - 1] != p && a[i][j - 1] >= 'A' && a[i][j - 1] <= 'Z' ){
                    flag[a[i][j - 1] - 'A'] = true ;
                }
                if ( a[i][j + 1] != p && a[i][j + 1] >= 'A' && a[i][j + 1] <= 'Z' ){
                    flag[a[i][j + 1] - 'A'] = true ;
                }
            }
        }
    }
    int cnt = 0 ;
    for(int i = 0; i < 26; i++){
        if ( flag[i] ) cnt++ ;
    }
    cout << cnt << endl;
    return 0 ;
}
