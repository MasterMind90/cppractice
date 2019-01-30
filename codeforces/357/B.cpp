#include <bits/stdc++.h>
using namespace std;
const int red = 1 ;
const int blue = 2 ;
const int green = 3 ;
int main(){
    int n , m ;
    cin >> n >> m ;
    vector<vector<int> > v ;
    int cnt[100001];
    int color[100001];
    memset(cnt,0,sizeof(cnt));
    memset(color,0,sizeof(color));
    for(int i=0;i<m;i++){
        vector<int> vv(3);
        for(int i=0;i<3;i++){
            cin >> vv[i];
            cnt[vv[i]]++;
        }
        v.push_back(vv);
    }
    for(int i=0;i<m;i++){
        vector<pair<int,int> > c ;
        for(int j=0;j<v[i].size();j++){
            c.push_back({cnt[v[i][j]],v[i][j]});
        }
        sort(c.rbegin(),c.rend());
        vector<pair<int,int> > k ;
        k.push_back({color[c[0].second],c[0].second});
        k.push_back({color[c[1].second],c[1].second});
        k.push_back({color[c[2].second],c[2].second});
        sort(k.rbegin(),k.rend());
        if ( k[0].first == 0 ) {
            color[c[0].second] = red ;
            color[c[1].second] = blue ;
            color[c[2].second] = green;
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
