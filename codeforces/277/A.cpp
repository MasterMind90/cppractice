#include <bits/stdc++.h>
using namespace std;
bool vis[100];
set<int> v[100];
void dfs(int x){
    if ( vis[x] ) return ;
    vis[x]=true;
    for(int p : v[x] ){
        dfs(p);
    }
}
int main(){
    int n , m ;
    cin >> n >> m ;
    vector<int> a[n];
    int zeros = 0;
    for(int i=0;i<n;i++){
        int c ;
        cin >> c;
        if ( c == 0 ) zeros++;
        for(int j=0;j<c;j++){
            int x;
            cin >> x ;
            a[i].push_back(x);
        }
        vis[i]=false;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i].size();j++){
            for(int k=0;k<n;k++){
                for(int p=0;p<a[k].size();p++){
                    if ( a[i][j] == a[k][p] ){
                        v[i].insert(k);
                        v[k].insert(i);
                    }
                }
            }
        }
    }
    int group = 0 ;
    for(int i=0;i<n;i++){
        if ( !vis[i] ){
            group++;
            dfs(i);
        }
    }
    cout << max(group-1,zeros) << endl;
    return 0 ;
}
