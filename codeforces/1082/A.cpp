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


int main(){
    int t ; 
    cin >> t ; 
    while(t--){
        int n , s, e, d ; 
        cin >> n >> s >> e >> d ; 
        if ( s == e ) {
            cout << 0 << endl;
            continue ; 
        }
        int diff = abs(e - s) ; 
        if ( diff % d == 0 ) {
            cout << diff/d << endl;
            continue ; 
        }
        diff = e - 1 ; 
        int diff2 = s - 1 ; 
        int moves = diff2/d ; 
        if ( diff2 % d != 0 ) moves++ ; 
        if ( diff % d == 0 ) moves+=(diff/d);
        else moves = INT_MAX ; 

        diff = n-s;
        int move2 = diff/d;
        if ( diff % d != 0 ) move2++;
        diff2 = n-e;
        if ( diff2 % d == 0 ) move2+=diff2/d;
        else move2 = INT_MAX ; 
        if ( move2 == moves && moves == INT_MAX ){
            cout << -1 << endl;
            continue ;
        }
        if ( moves <= move2 ){
            cout << moves << endl;
        }
        else cout << move2 << endl;
    }
    
    return 0;
}
