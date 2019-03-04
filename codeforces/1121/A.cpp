#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m , k ; 
    cin >> n >> m >> k ; 
    vector<int> v(n+1);
    vector<int> school(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    map<int,vector<int> > ma ; 
    for(int i=1;i<=n;i++){
        cin >> school[i];
        ma[school[i]].push_back(v[i]);
        sort(ma[school[i]].rbegin(),ma[school[i]].rend());
    }
    int ans = 0 ;
    for(int i=0;i<k;i++){
        int id ; 
        cin >> id ; 
        int power = v[id] ;
        int schol = school[id];
        if ( ma[schol][0] != power )
            ans++;
    }
    cout << ans << endl;
    return 0 ;
}
