#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10 ;
int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    vector<int> cnt(MAXN) ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
        cnt[v[i]]++;
        cnt[v[i]+1]++;
        cnt[ ((v[i]-1)%MAXN+MAXN)%MAXN ]++;
    }
    cout << *max_element(cnt.begin(),cnt.end()) << endl;
    return 0 ;
}
