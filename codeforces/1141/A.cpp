#include <bits/stdc++.h>
using namespace std;

int n , m ;

bool dfs(int n,int cnt){
    if ( n == m ){
        cout << cnt << endl;
        return true ;
    }
    if ( n > m ) {
        return false ;
    }

    if ( dfs(n*2,cnt+1) ){
        return true ;
    }
    if ( dfs(n*3,cnt+1) ){
        return true ;
    }
    return false ;
}

int main(){
    cin >> n >> m ;
    if ( !dfs(n,0) ){
        cout << -1 << endl;
    }
    return 0 ;
}
