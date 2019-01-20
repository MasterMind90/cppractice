#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int sum = 0 ;
    int i;
    for(i=0;i<n;i++){
        if ( v[i] <= k ) sum++;
        else break;
    }
    if ( i == n ){
        cout << sum << endl;
    }
    else{
        int sum2 = 0 ;
        for(int i=n-1;i>=0;i--){
            if ( v[i] <= k ) sum2++;
            else break;
        }
        cout << sum + sum2 << endl;
    }
    return 0 ;
}
