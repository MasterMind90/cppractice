#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    int MAX , MIN ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());

    int m = min(v[v.size()-2] - v[0],v[v.size()-1]-v[1]);

    cout << m << endl;
    return 0 ;
}
