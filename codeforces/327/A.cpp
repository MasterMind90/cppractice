#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    vector<int> sum(n+2);
    vector<int> ones(n+2);
    sum[0] = 0 ;
    ones[0] = 0 ;
    sum[n+1] = 0 ;
    ones[n+1] = 0 ;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if ( v[i] == 0 ) {
            sum[i+1] = sum[i] + 1 ;
            ones[i+1] = ones[i];
        }
        else {
            ones[i+1] = ones[i]+1;
            sum[i+1] = sum[i];
        }
    }
    int MAX = -1e9;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            MAX = max(MAX,(sum[j]-sum[i-1]) + ones[i-1] + (ones[n] - ones[j]) );
        }
    }
    cout << MAX << endl;
    return 0 ;
}
