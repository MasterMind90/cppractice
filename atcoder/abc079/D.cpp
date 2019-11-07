#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 + 10 ;
int main(){
    int n , m ;
    cin >> n >> m ;
    vector<vector<int> > c(10, vector<int>(10));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> c[i][j] ;
            if ( c[i][j] == 0 ) c[i][j] = INF ;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if ( c[j][i] + c[i][k] < c[j][k] ){
                    c[j][k] = c[j][i] + c[i][k] ;
                }
            }
        }
    }
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x ;
            cin >> x ;
            if ( x == -1 || x == 1) continue ;
            ans += c[x][1] ;
        }
    }
    cout << ans << endl;
    return 0 ;
}