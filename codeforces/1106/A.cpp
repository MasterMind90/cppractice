#include <bits/stdc++.h>
using namespace std;

#define ABS(x) ((x)<0 ? -(x) : (x))
#define REP(i,n) for(int i=0, _e(n); i<_e; i++)
#define SET(t,v) memset((t), (v), sizeof(t))
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize( unique( ALL(c) ) - (c).begin() )

#define sz size()
#define pb push_back

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;

#ifdef DEBUG
#define dbg(x) x
#define dbgp(x) cerr << x ;
#else
#define dbg(x) //x
#define dbgp(x) //cerr << x << endl;
#endif

char grid[504][504];

int main(){
    int n ; 
    cin >> n ; 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> grid[i][j] ; 
        }
    }
    long long ans = 0 ; 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if ( grid[i][j] == 'X' && grid[i-1][j-1] == 'X' && grid[i-1][j+1] == 'X' && grid[i+1][j-1] == 'X' && grid[i+1][j+1] == 'X' ) ans++ ; 
        }
    }
    cout << ans << endl;

    return 0;
}
