#include <bits/stdc++.h>
using namespace std;

int main(){
    int n  ; 
    cin >> n ; 
    vector<int> v(n+1);
    map<int,vector<int> > m ; 
    for(int i=1;i<=n;i++){
        cin >> v[i] ; 
        m[v[i]].push_back(i);
    }
    vector<bool> flag(n+1,0);
    int days = 0 ; 
    for(int i=1;i<=n;i++){
        for(int j=0;j<m[i].size();j++){
            flag[m[i][j]] = true ; 
        }
        bool ok = true ; 
        for(int j=1;j<=i;j++){
            if ( flag[j] == false ){
                ok = false ; 
                break;
            }
        }
        if ( ok ) days++;
    }
    cout << days << endl;
    return 0 ; 
}
