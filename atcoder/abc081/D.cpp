#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    int MAX = -1e9 ;
    int MIN = 1e9 ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
        MAX = max(MAX,v[i]);
        MIN = min(MIN,v[i]);
    }
    vector<pair<int,int> > ans ;
    if ( abs(MAX) >= abs(MIN) ){
        int maxIndex = max_element(v.begin(),v.end()) - v.begin();
        maxIndex++;
        for(int i=0;i<n;i++){
            if ( i+1 == maxIndex ) continue ;
            ans.push_back({maxIndex,i+1});
        }
        ans.push_back({maxIndex,maxIndex});
        for(int i=1;i<n;i++){
            ans.push_back({i,i+1});
        }
    }
    else{
        int minIndex = min_element(v.begin(),v.end()) - v.begin();
        minIndex++;
        for(int i=0;i<n;i++){
            if ( i+1 == minIndex ) continue ;
            ans.push_back({minIndex,i+1});
        }
        ans.push_back({minIndex,minIndex});
        for(int i=n;i>1;i--){
            ans.push_back({i,i-1});
        }
    }
    cout << ans.size() << endl;
    for(auto &p : ans){
        cout << p.first << " " << p.second << endl;
    }
    return 0 ;
}
