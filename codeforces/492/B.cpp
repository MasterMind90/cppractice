#include <bits/stdc++.h>
using namespace std;
int n , m ;
vector<int> v ;
bool p(double d){
    double t = 0 ; 
    for(int i=0;i<n;i++){
        if ( v[i]-d <= t ) {
            t = v[i]+d;
            continue;
        }
        else return false;
    }
    if ( v[n-1] + d >= m ) return true ;
    return false;
}
int main(){
    cin >> n >> m ;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    double l = 1e-9 ; 
    double r = 1e10 ;
    int x = 100 ;
    while(x--){
        double mid = l + (r-l)/2.0 ;
        if ( p(mid) == true ){
            r = mid ;
        }
        else {
            l = mid ; 
        }
    }
    cout << fixed << setprecision(9) << l << endl;
    return 0;
}
