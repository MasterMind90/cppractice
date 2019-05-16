#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5*1e5+10;
int parent[MAXN] ;
int ans[MAXN] ;
int Find(int x){
    if ( x != parent[x] ){
        parent[x] = Find(parent[x]);
    }
    return parent[x] ;
}
void Union(int x,int y){
    parent[Find(x)] = Find(y);
}
int main(){
    int n , m ;
    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        parent[i] = i ;
    }
    for(int i=0;i<m;i++){
        int k ;
        cin >> k ;
        int pre = 0 ;
        for(int i=0;i<k;i++){
            int x ;
            cin >> x ;
            if ( i != 0 ){
                Union(pre,x);
            }
            pre = x ;
        }
    }
    for(int i=1;i<=n;i++){
        ans[Find(i)]++;
    }
    for(int i=1;i<=n;i++){
        cout << ans[Find(i)] << ' ';
    }
    cout << endl;
    return 0 ;
}
