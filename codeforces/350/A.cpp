#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    sort(b.begin(),b.end());
    if ( 2*a[0] < b[0] && a[a.size()-1] < b[0] ){
        if ( 2*a[0] <= a[a.size()-1] ){
            cout << a[a.size()-1] << endl;
            return 0 ;
        }
        else{
            cout << 2*a[0] << endl;
            return 0 ;
        }
    }
    cout << -1 << endl;
    return 0 ;
}
