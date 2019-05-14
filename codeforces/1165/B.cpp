#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n ;
    vector<int> v(n) ;
    for(int &x : v){
        cin >> x ;
    }
    sort(v.begin(),v.end());
    int cur = 1 ;
    int days = 0 ;
    for(int i=0;i<n;i++){
        if ( v[i] >= cur ){
            cur++;
            days++;
        }
    }
    cout << days << endl;
    return 0 ;
}
