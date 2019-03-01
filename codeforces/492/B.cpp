#include <bits/stdc++.h>
using namespace std;
int n , l ; 
vector<int> v ;
int main(){
    cin >> n >> l ;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int dist = 0 ; 
    for(int i=1;i<n;i++){
        dist = max(dist,v[i]-v[i-1]);
    }
    double ans = dist / 2.0 ;
    ans = max((double)v[0],ans);
    ans = max(ans,(double)(l-v[v.size()-1]));
    cout << fixed << setprecision(9) << ans << endl;
    return 0 ; 
}
