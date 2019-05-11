#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k ;
    cin >> n >> k ;
    map<int,int> m ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        m[x]++;
    }
    vector<int> v ;
    for(auto &p : m){
        v.push_back(p.second);
    }
    sort(v.rbegin(),v.rend());
    int ans = 0 ;
    int cnt = 1 ;
    for(int i=0;i<v.size();i++){
        if ( cnt > k ){
            ans += v[i] ;
        }
        cnt++;
    }
    cout << ans << endl;
    return 0 ;
}
