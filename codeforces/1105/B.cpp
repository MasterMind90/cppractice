#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v[26];
    int n , k ;
    cin >> n >> k ;
    string x ;
    cin >> x ;
    int cnt = 1 ;
    for(int i=1;i<x.size();i++){
        if ( x[i] != x[i-1] ){
            v[x[i-1]-'a'].push_back(cnt);
            cnt = 1 ;
        }
        else cnt++;
    }
    v[x[x.size()-1]-'a'].push_back(cnt);
    int MAX = 0 ;
    for(int i=0;i<26;i++){
        sort(v[i].begin(),v[i].end());
        int index = lower_bound(v[i].begin(),v[i].end(),k) - v[i].begin();
        if ( index == -1 ) continue ;
        int ans = 0 ;
        for(int j=index;j<v[i].size();j++){
            ans += v[i][j]/k;
        }
        MAX = max(MAX,ans);
    }
    cout << MAX << endl;
    return 0 ;
}
