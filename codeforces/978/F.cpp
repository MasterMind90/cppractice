#include <bits/stdc++.h>
using namespace std;
int ans[2*100001];
int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int> v(n);
    vector<int> order(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        order[i] = v[i];

    }
    sort(v.begin(),v.end());
    map<int,vector<int> > m ;
    for(int i=0;i<k;i++){
        int x , y ;
        cin >> x >> y ;
        x--,y--;
        if ( m.find(x) != m.end() ){
            if ( order[y] < order[x] )
                m[x].push_back(y);
        }
        else {
            vector<int> vv ;
            vv.push_back(y);
            if ( order[y] < order[x] )
                m[x] = vv ;
        }
        if ( m.find(y) != m.end() ){
            if ( order[x] < order[y] )
                m[y].push_back(x);
        }
        else {
            vector<int> vv ;
            vv.push_back(x);
            if ( order[x] < order[y] )
                m[y] = vv ;
        }
    }
    for(int i=0;i<n;i++){
        int x = order[i];
        int index = upper_bound(v.begin(),v.end(),x-1) - v.begin() ;
        auto it = m.find(i);
        if ( it == m.end() ) {
            cout << index << " " ;
        }
        else{
            cout << index-it->second.size() << " " ;
        }
    }
    cout << endl;
    return 0 ;
}
