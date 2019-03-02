#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ; 
    cin >> n ; 
    vector<int> v(n+1) ; 
    map<int,pair<int,int> > m ; 
    for(int i=1;i<=n;i++){
        cin >> v[i];
        m[v[i]].first = i ; 
        m[v[i]].second = n - i + 1 ;
    }
    int q ; 
    cin >> q ;
    long long f = 0 , s = 0 ;
    while(q--){
        int x ;  
        cin >> x ;
        f+=m[x].first ; 
        s+=m[x].second ; 
    }
    cout << f << " " << s << endl;
    return 0 ;
}
