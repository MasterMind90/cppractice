#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ; 
    cin >> n ; 
    vector<int> v(n);
    int sum = 0 ;
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum += v[i];
    }
    sort(v.rbegin(),v.rend());
    int ans = sum;
    for(int i=0;i<n;i++){
        for(int j=2;j<v[i];j++){
            if ( v[i] % j == 0 ){
                int newSum = sum - v[i];
                newSum += v[i]/j;
                newSum -= v[n-1];
                newSum += v[n-1]*j;
                ans = min(ans,newSum);
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}
