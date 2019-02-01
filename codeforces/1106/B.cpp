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
    int n , m ; 
    cin >> n >> m ; 
    priority_queue<pair<pair<long long,long long>,long long>, vector<pair<pair<long long,long long>,long long> > , greater<pair<pair<long long,long long>,long long> > > q ; 
    vector<pair<long long,long long> > v(n+1) ; 
    for(int i=1;i<=n;i++){
        cin >> v[i].first ; 
    }
    for(int i=1;i<=n;i++){
        cin >> v[i].second ; 
    }
    for(int i=1;i<=n;i++){
        q.push({{v[i].second,i},v[i].first});
    }
    while(m--){
        long long kind , quan ; 
        cin >> kind >> quan ; 
        long long sum = 0 ; 
        long long mm = min(quan,v[kind].first) ; 
        sum +=  mm * v[kind].second ; 
        v[kind].first -= mm ; 
        quan -= mm ; 
        while(quan > 0){
            if ( q.size() <= 0 ) break ; 
            long long index = q.top().first.second ; 
            if ( index == kind ) q.pop() ; 
            if ( q.size() <= 0 ) break ; 
            index = q.top().first.second ; 
            long long cost = q.top().first.first ; 
            long long qq = v[index].first ;
            q.pop() ; 
            mm = min(quan,qq) ; 
            v[index].first -= mm ; 
            quan-=mm ; 
            qq-=mm ; 
            sum += mm*cost ; 
            if ( qq > 0 ) q.push({{cost,index},qq}) ; 
        }
        if ( quan > 0 ) {
            cout << 0 << endl;
        }
        else cout << sum << endl;
    }
    
    return 0;
}
