#include <bits/stdc++.h>
using namespace std;

vector<int> g[2*100001] ;
int deg[2*100001] ;
bool vis[2*100001] ;
bool flag ;

void dfs(int x){
    if ( deg[x] != 2 ) flag = true ;
    if ( vis[x] ) return ;
    vis[x] = true ;
    for(int p : g[x]){
        dfs(p);
    }
}

int main(){
    int n , m ;
    cin >> n >> m ;
    while(m--){
        int x, y ;
        cin >> x >> y ;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++;
        deg[y]++;

    }
    int cnt = 0 ;
    for(int i=0;i<n;i++){
        if ( !vis[i] ){
            flag = false ;
            dfs(i) ;
            if ( !flag ) cnt++ ;
        }
    }
    cout << cnt << endl;

    return 0 ;
}
