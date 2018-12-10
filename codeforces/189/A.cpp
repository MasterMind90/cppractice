#include <bits/stdc++.h>
using namespace std;
vector<int> a ;
int ar[5000];
int backtrack(int n,int level){
    if ( n < 0 ) return -1e6 ;
    if ( n == 0 ){
        return level ;
    }
    if ( ar[n] != 0 ) return ar[n];
    int MAX = -1e6 ;
    for(int i=0;i<a.size();i++){
        int c = backtrack(n-a[i],level+1);
        MAX = max(MAX,c);
    }
    ar[n] = MAX ;
    return MAX ;
}
int main(){
    int n ;
    a.resize(3);
    cin >> n >> a[0] >> a[1] >> a[2] ;
    if ( a[0] == 1 || a[1] == 1 || a[2] == 1 ){
        cout << n << endl;
        return 0;
    }
    sort(a.begin(),a.end());
    auto last = unique(a.begin(),a.end());
    a.erase(last,a.end());
    int res = backtrack(n,0);
    cout << res << endl;
    return 0 ;
}
