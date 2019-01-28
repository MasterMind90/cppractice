#include <bits/stdc++.h>
using namespace std;
int n , b ;
vector<int> v ;
bool check(int start, int x){
    int e = 0 , o = 0 ;
    for(int i=start;i<x;i++){
        if ( v[i] % 2 == 0 ) e++ ;
        else o++;
    }
    if ( e != o ) return false ;
    return true ;
}
int main(){
    cin >> n >> b ;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> ans ;
    for(int i=2;i<n;i+=2){
        if ( check(0,i) && abs(v[i]-v[i-1]) <= b ){
            ans.push_back(abs(v[i]-v[i-1]));
        }
    }
    sort(ans.begin(),ans.end());
    int cnt = 0 ;
    for(int i=0;i<ans.size();i++){
        if ( ans[i] <= b ) {
            cnt++;
            b-=ans[i];
        }
        else break;
    }
    cout << cnt << endl;
    return 0 ;
}
