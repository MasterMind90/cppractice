#include <bits/stdc++.h>
using namespace std;
bool ar[100001];
int main(){
    int n , m ;
    cin >> n >> m ;
    vector<int> v(n) ;
    vector<int> u(n+2);
    u[0] = 0  ;
    u[n+1] = 0 ;
    int x = n ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=n;i>0;i--){
        if ( ar[v[i-1]] == false ){
            u[i] = u[i+1] + 1;
            ar[v[i-1]] = true ;
        }
        else u[i] = u[i+1];
    }
    while(m--){
        int x ;
        cin >> x ;
        cout << u[x] << endl;
    }
    return 0 ;
}
