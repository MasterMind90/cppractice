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
int n , m ; 
bool flag[100005] ; 

vector< priority_queue<int,vector<int>,greater<int> > > v ; 

int main(){
    cin >> n >> m ; 
    v.resize(n+1); 
    REP(i,m){
        int x , y ; 
        cin >> x >> y ; 
        if ( x == y ) continue ; 
        v[x].push(y);
        v[y].push(x);
    }
    priority_queue<int,vector<int>,greater<int> > q ; 
    q.push(1) ; 
    flag[1] = true ; 
    set<int> s ; 
    vector<int> vv ; 
    while(!q.empty()){
        int top = q.top() ; q.pop() ; 
        if ( s.find(top) == s.end() ) {
            vv.push_back(top) ; 
            s.insert(top) ; 
        }
        while(v[top].size()){
            int tt = v[top].top() ; v[top].pop() ; 
            if ( !flag[tt] ) q.push(tt);
        }
    }
    for(int p : vv){
        cout << p << " " ; 
    }
    cout << endl;
    return 0;
}
