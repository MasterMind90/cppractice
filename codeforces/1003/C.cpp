#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k ;
    cin >> n >> k ;
    vector<long long> v(n+2);
    vector<long long> sum(n+2,0);
    sum[0] = 0 ;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        sum[i] = sum[i-1] + v[i];
    }
    double MAX = 0 ;
    for(int i=0;i<=n-k;i++){
        for(int j=i+k;j<=n;j++){
            int k = j-i;
            long long s = sum[j] - sum[i];
            double average = s/((double)k) ;
            if ( average > MAX ) {
                MAX = average ;
            }
        }
    }
    cout << fixed << setprecision(9) <<  MAX << endl;
    return 0 ;
}
