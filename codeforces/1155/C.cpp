#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , m ;
    cin >> n >> m ;
    vector<long long> x(n);
    vector<long long> diff;
    long long ans ;
    for(int i=0;i<n;i++){
        cin >> x[i] ;
        if ( i != 0 )
            diff.push_back(x[i]-x[i-1]);
    }
    vector<long long> p(m);
    for(int i=0;i<m;i++){
        cin >> p[i] ;
        if ( p[i] == 1 ){
            cout << "YES" << endl;
            cout << x[0] << " " << i+1 << endl;
            return 0 ;
        }
    }
    if ( x.size() == 1 ){
        cout << "YES" << endl;
        cout << x[0] << " " << 1 << endl;
        return 0 ;
    }
    ans = diff[0];
    for(int i=1;i<diff.size();i++){
        ans = gcd(ans,diff[i]);
    }
    //cout << ans << endl;
    if ( ans == 1 ){
        cout << "NO" << endl;
        return 0 ;
    }
    for(int i=0;i<p.size();i++){
        if ( p[i] == ans ){
            cout << "YES" << endl;
            cout << x[0] << " " << i+1 << endl;
            return 0 ;
        }
        else if ( p[i] < ans ){
            if ( ans % p[i] == 0 ){
                cout << "YES" << endl;
                cout << x[0] << " " << i+1 << endl;
                return 0 ;
            }
        }
    }
    cout << "NO" << endl;
    return 0 ;
}
