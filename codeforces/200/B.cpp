#include <bits/stdc++.h>
using namespace std;

int main(){
    double n ;
    cin >> n ;
    double sum = 0 ;
    for(int i=0;i<n;i++){
        double x ;
        cin >> x ;
        sum += x ;
    }
    sum/=100.0;
    double ans = sum/n ;
    ans*=100;
    cout << fixed << setprecision(9) << ans << endl;

    return 0 ;
}
