#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<pair<int,int> > v(n) ;
    vector<pair<int,int> > c(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second ;
    }
    for(int i=0;i<n;i++){
        cin >> c[i].first >> c[i].second ;
    }
    vector<pair<int,int> > all[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            all[i].push_back({v[i].first+c[j].first,v[i].second+c[j].second});
        }
    }
    /*
    for(int i=0;i<n;i++){
        for(pair<int,int> &p : all[i]){
            cout << p.first << " " << p.second << endl;
        }
        cout << endl;
    }
    */
    for(pair<int,int> &p : all[0]){
        int ans = 1 ;
        for(int i=1;i<n;i++){
            for(pair<int,int> &p2 : all[i]){
                if (p.first == p2.first && p.second == p2.second ){
                    ans++;
                    break;
                }
            }
        }
        if ( ans == n ){
            cout << p.first << " " << p.second << endl;
            return 0 ;
        }
    }
    return 0 ;
}
