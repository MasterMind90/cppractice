#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5*1e5+10;
int cnt = 0 ;
set<int> s[MAXN] ;
bool vis[MAXN] ;
bool vis2[MAXN] ;
int ans[MAXN] ;

void dfs(int x){
    if ( vis[x] ) return ;
    vis[x] = true ;
    cnt++;
    for(int c : s[x]){
        dfs(c);
    }
}
void dfs2(int x){
    if ( vis2[x] ) return ;
    vis2[x] = true ;
    ans[x] = cnt ;
    for(int c : s[x]){
        dfs2(c);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , m ;
    cin >> n >> m ;
    for(int i=0;i<m;i++){
        int k ;
        cin >> k ;
        int pre = 0 ;
        for(int i=0;i<k;i++){
            int x ;
            cin >> x ;
            if ( i != 0 ){
                s[x].insert(pre);
                s[pre].insert(x);
            }
            pre = x ;
        }
    }
    for(int i=1;i<=n;i++){
        if ( vis2[i] ){
            continue ;
        }
        cnt = 0 ;
        dfs(i);
        dfs2(i);
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ' ;
    }
    cout << endl;

    return 0 ;
}
