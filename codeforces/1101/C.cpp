#include <bits/stdc++.h>
using namespace std;
int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        vector<pair<int,int> > v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].first >> v[i].second ;
        }
        vector<pair<int,int> > order = v;
        sort(v.begin(),v.end());
        int l = v[0].first ;
        int r = v[0].second ;
        int index = -1 ;
        for(int i=1;i<v.size();i++){
            if ( v[i].first > r ){
                index = i ;
                break;
            }
            else r = max(r,v[i].second) ;
        }
        if ( index == -1 ) {
            cout << -1 << endl;
        }
        else{
            map<pair<int,int> , int > m ;
            for(int i=0;i<index;i++){
                m[{v[i].first,v[i].second}] = 1 ;
            }
            for(int i=0;i<n;i++){
                if ( m[{order[i].first,order[i].second}] ){
                    cout << 1 << " " ;
                }
                else cout << 2 << " " ;
            }
            cout << endl;
        }
    }
    return 0 ;
}
