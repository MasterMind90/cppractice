#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k ;
    cin >> k ;
    vector<pair<long long,pair<int,int> > > ans ;
    for(int i=0;i<k;i++){
        int n ;
        cin >> n ;
        vector<int> v(n);
        long long sum = 0LL ;
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum += v[i];
        }
        for(int j=0;j<n;j++){
            ans.push_back({sum-v[j],{i,j}} ) ;
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size()-1;i++){
        if ( ans[i].first == ans[i+1].first && ans[i].second.first != ans[i+1].second.first ){
            cout << "YES" << endl;
            cout << ans[i].second.first+1 << " " << ans[i].second.second+1 << endl;
            cout << ans[i+1].second.first+1 << " " << ans[i+1].second.second+1 << endl;
            return 0 ;
        }
    }
    cout << "NO" << endl;
    return 0 ;
}
