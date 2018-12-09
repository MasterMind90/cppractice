#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    map<int,vector<int> > m ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
        m[v[i]].push_back(i) ;
    }
    vector<pair<int,int> > ans ;
    for(auto p : m){
        if ( p.second.size() == 1 ){
            ans.push_back({p.first,0});
        }
        else{
            int diff = p.second[1]-p.second[0];
            bool f = false ;
            for(int i=1;i<p.second.size();i++){
                if ( p.second[i] - p.second[i-1] == diff ) continue ;
                else {
                    f = true ;
                    break ;
                }
            }
            if ( f == false ) {
                ans.push_back({p.first,diff});
            }
        }
    }
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }



    return 0 ;
}
