#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n , k ;
    cin >> n >> k ;
    vector<long long> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    string x ;
    cin >> x ;
    vector<long long> ans ;
    ans.push_back(v[0]);
    long long res = 0 ;
    for(int i=1;i<=x.size();i++){
        if ( x[i] != x[i-1] ){
            sort(ans.begin(),ans.end());
            reverse(ans.begin(),ans.end());
            for(int i=0;i<min(k,(long long)ans.size());i++){
                res+=ans[i];
            }
            ans.clear();
            if ( i == x.size() ) continue ;
            ans.push_back(v[i]);
        }
        else{
            ans.push_back(v[i]);
        }
    }
    cout << res << endl;
    return 0 ;
}
