#include <bits/stdc++.h>
using namespace std;
char g[12][12];
int check(int x,int y){
    int ans = 0 ;
    if ( g[x-1][y] == 'W' ) ans++;
    if ( g[x+1][y] == 'W' ) ans++;
    if ( g[x][y-1] == 'W' ) ans++;
    if ( g[x][y+1] == 'W' ) ans++;
    return ans ;
}
int main(){
    int n , m ;
    cin >> n >> m ;
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            g[i][j] = '.';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> g[i][j];
        }
    }
    int ans = 0 ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if ( g[i][j] == 'W' ){
                vector<pair<int,pair<int,int> > > v;
                bool flag = false ;
                if ( g[i+1][j] == 'P' ){
                    flag = true ;
                    v.push_back( {check(i+1,j),{i+1,j} }  );
                }
                if ( g[i-1][j] == 'P' ){
                    flag = true ;
                    v.push_back( {check(i-1,j),{i-1,j} } );
                }
                if ( g[i][j-1] == 'P' ){
                    flag = true ;
                    v.push_back( {check(i,j-1),{i,j-1} } );
                }
                if ( g[i][j+1] == 'P' ){
                    flag = true ;
                    v.push_back( {check(i,j+1),{i,j+1} } );
                }
                if ( flag ){
                    sort(v.begin(),v.end());
                    ans++;
                    g[i][j] = '.';
                    g[v[0].second.first][v[0].second.second] = '.';
                }
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}
