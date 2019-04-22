#include <bits/stdc++.h>
using namespace std;

int X[] = {-1,-1,-1,0,0,1,1,1} ;
int Y[] = {-1,0,1, 1,-1,1,0,-1} ;

bool allowed(int x,int y,map<int,vector<pair<int,int> > > &grid){
    if ( grid[x].size() ){
        for(auto &p : grid[x] ){
            if ( y >= p.first && y <= p.second ) return true ;
        }
    }
    return false ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x , y , a , b ;
    cin >> x >> y >> a >> b ;
    int n ;
    cin >> n ;
    map<int,vector<pair<int,int> > > grid ;
    for(int i=0;i<n;i++){
        int r , a , b ;
        cin >> r >> a >> b ;
        vector<pair<int,int> > &v = grid[r] ;
        if ( v.size() ){
            bool f = false ;
            for(auto &p : v){
                if ( a > p.second || p.first > b ) continue ;
                p.first = min(p.first,a);
                p.second = max(p.second,b);
                f = true ;
                break;
            }
            if ( !f ) v.push_back({a,b});
        }
        else{
            v.push_back({a,b});
        }
    }
    map<pair<int,int>,int> dist ;
    map<pair<int,int>,bool> vis ;
    queue<pair<int,int> > q ;
    q.push({x,y});
    dist[{x,y}] = 0 ;
    while(q.size()){
        auto p = q.front() ; q.pop();
        if ( p.first == a && p.second == b ){
            cout << dist[{a,b}] << endl;
            return 0 ;
        }
        for(int i=0;i<8;i++){
            int x = p.first + X[i] ;
            int y = p.second + Y[i] ;
            if ( allowed(x,y,grid) && !vis[{x,y}] ){
                vis[{x,y}] = true ;
                dist[{x,y}] = dist[{p.first,p.second}] + 1 ;
                q.push({x,y});
            }
        }
    }
    cout << -1 << endl;
    return 0 ;
}
