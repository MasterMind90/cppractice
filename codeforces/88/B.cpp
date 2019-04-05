#include <bits/stdc++.h>
using namespace std;

long long getDist(long long x1,long long y1, long long x2,long long y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){
    long long n , m , xx;
    cin >> n >> m >> xx ;
    xx = xx * xx ;
    char grid[n][m] ;
    long long dist[26] ;
    for(int i=0;i<26;i++){
        dist[i] = 1e18;
    }
    bool letter[26] = {0} ;
    memset(letter,0,sizeof letter);
    bool ok = false ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j] ;
            if ( grid[i][j] == 'S' ) ok = true ;
            else letter[grid[i][j]-'a'] = true ;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if ( grid[i][j] >= 'a' && grid[i][j] <= 'z' ){
                for(int k=0;k<n;k++){
                    for(int c=0;c<m;c++){
                        if ( grid[k][c] == 'S' ){
                            dist[grid[i][j]-'a'] = min(dist[grid[i][j]-'a'],getDist(i,j,k,c));
                        }
                    }
                }
            }
        }
    }
    int q ;
    cin >> q ;
    string x ;
    cin >> x ;
    long long ans = 0 ;
    for(int i=0;i<x.size();i++){
        if ( x[i] >= 'a' && x[i] <= 'z' ){
            if ( !letter[x[i]-'a'] ) {
                cout << -1 << endl;
                return 0 ;
            }
        }
        else{
            if ( !ok ){
                cout << -1 << endl;
                return 0 ;
            }
            else {
                if ( !letter[x[i]-'A'] ){
                    cout << -1 << endl;
                    return 0 ;
                }
                if ( dist[x[i]-'A'] > xx ) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}
