#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool taken[1001];
int main(){
    set<long long> s[1001];
    long long n , m ;
    cin >> n >> m ;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    while(m--){
        int x , y ;
        cin >> x >> y ;
        x--,y--;
        s[x].insert(y);
        s[y].insert(x);
    }
    long long cost = 0 ;
    for(int i=0;i<n;i++){
        long long MAX = -1e17;
        long long maxIndex = -1 ;
        for(int j=0;j<n;j++){
            if ( !taken[j] && (v[j] > MAX) ){
                MAX = v[j];
                maxIndex=j;
            }
        }
        if ( maxIndex == -1 ) break;
        //cout << maxIndex << endl;
        taken[maxIndex]=true;
        long long ans = 0 ;
        for(auto p : s[maxIndex]) {
            //cout << "--" << p << endl;
            ans+=v[p];
        }
        cost+=ans;
        //cout << ans << endl;
        s[maxIndex].clear();
        for(int j=0;j<n;j++){
            auto it = s[j].find(maxIndex);
            if ( it == s[j].end() ) continue;
            s[j].erase(it);
        }
    }
    cout << cost << endl;
    return 0 ;
}
