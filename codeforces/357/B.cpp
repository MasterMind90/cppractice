#include <bits/stdc++.h>
using namespace std;
const int red = 1 ;
const int blue = 2 ;
const int green = 3 ;
int main(){
    int n , m ;
    cin >> n >> m ;
    vector<vector<int> > v ;
    int color[100001];
    memset(color,0,sizeof(color));
    for(int i=0;i<m;i++){
        vector<int> vv(3);
        for(int i=0;i<3;i++){
            cin >> vv[i];
        }
        v.push_back(vv);
    }
    for(int i=0;i<m;i++){
        vector<pair<int,int> > k ;
        k.push_back({color[v[i][0]],v[i][0]});
        k.push_back({color[v[i][1]],v[i][1]});
        k.push_back({color[v[i][2]],v[i][2]});
        sort(k.rbegin(),k.rend());
        if ( k[0].first == 0 ) {
            color[k[0].second] = red ;
            color[k[1].second] = blue ;
            color[k[2].second] = green;
        }
        else if ( k[0].first == red ){
            color[k[1].second] = green ;
            color[k[2].second] = blue ;
        }
        else if ( k[0].first == green ){
            color[k[1].second] = red ;
            color[k[2].second] = blue ;
        }
        else if ( k[0].first == blue ){
            color[k[1].second] = red ;
            color[k[2].second] = green ;
        }
    }
    for(int i=1;i<=n;i++){
        cout << color[i] << " " ;
    }
    cout << endl;
    return 0 ;
}
