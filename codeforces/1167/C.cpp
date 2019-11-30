#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int rep[N] ; 
int cnt[N] ; 

int Find(int x){
    if ( x == rep[x] ) return x ;
    rep[x] = Find(rep[x]) ; 
    return rep[x] ; 
}
void Union(int x,int y){
    int X = Find(x) ; 
    int Y = Find(y) ; 
    if ( X == Y ) return  ;
    rep[X] = Y ; 
    cnt[Y] += cnt[X] ; 
}

int main(){
    for(int i = 0; i < N; i++) rep[i] = i, cnt[i] = 1 ;
    int n , m ; 
    cin >> n >> m ; 
    for(int i = 0; i < m; i++){
        int k ; 
        cin >> k ; 
        int pre = -1 ;
        for(int j = 0; j < k; j++){
            int x ; 
            cin >> x ; 
            if ( j == 0 ) pre = x ; 
            else{
                Union(x, pre) ; 
                pre = x ;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << cnt[Find(i)] << ' ' ; 
    }
    cout << endl;
    return 0 ;
}