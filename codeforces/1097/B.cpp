#include <bits/stdc++.h>
using namespace std;
int clockwise(int cur,int x){
    return (cur+x)%360;
}
int counterwise(int curr,int x){
    if ( curr-x < 0 ) {
        return 360+(curr-x);
    }
    return curr-x;
}
int n ;
vector<int> v;
bool dfs(int curr,int n){
    if ( n == ::n ) {
        if ( curr == 0 ) return true ;
        else return false ;
    }
    if ( dfs(clockwise(curr,v[n]),n+1) == true ) return true ;
    if ( dfs(counterwise(curr,v[n]),n+1) == true ) return true ;
    return false ;
}

int main(){
    int n ;
    cin >> n ;
    ::n = n ;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    if ( dfs(0,0) == true ){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

    return 0 ;
}
