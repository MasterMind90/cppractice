#include <bits/stdc++.h>
using namespace std;
bool vis[5005];
bool vis2[5005];
vector<int> v[5005];
int n , m , s ;
int cnt = 0 ;
void dfs(int x){
    if ( x < 0 || x >= n || vis[x] ) return ;
    vis[x] = true ;
    cnt++;
    for(int c : v[x]){
        dfs(c);
    }
}
void dfs2(int x){
    if ( x < 0 || x >= n || vis2[x] ) return ;
    vis2[x] = true ;
    cnt++;
    for(int c : v[x]){
        dfs2(c);
    }
}
int main(){
    cin >> n >> m >> s ;
    for(int i=0;i<m;i++){
        int x , y ;
        cin >> x >> y ;
        x--,y--;
        v[x].push_back(y);
    }
    s--;
    dfs(s);
    vector<pair<int,int> > d ;
    for(int i=0;i<n;i++){
        for(int i=0;i<n;i++){
            vis2[i] = vis[i];
        }
        if ( !vis[i] ){
            cnt = 0 ;
            dfs2(i);
            d.push_back({cnt,i});
        }
    }
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    int ans = 0 ;
    for(int i=0;i<d.size();i++){
        if ( !vis[d[i].second] ){
            dfs(d[i].second);
            ans++;
        }
    }
    cout << ans << endl;
    return 0 ;
}
