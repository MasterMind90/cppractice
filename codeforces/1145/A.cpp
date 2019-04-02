#include <bits/stdc++.h>
using namespace std;
int dfs(int l,int r,vector<int> &v){
    if ( is_sorted(v.begin()+l,v.begin()+r) ){
        return r - l ;
    }
    int m = (l + r) / 2 ;
    int nax1 = dfs(l,m,v) ;
    int nax2 = dfs(m,r,v);
    return max(nax1,nax2);
}
int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int &x : v){
        cin >> x ;
    }
    cout << dfs(0,n,v) << endl;
    return 0 ;
}
