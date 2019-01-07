#include <bits/stdc++.h>
using namespace std;
int clockwise(int cur,int x){
    return (cur+x)%360;
}
int counterwise(int curr,int x){
    if ( curr-x < 0 ) {
        return 360+(curr-x);
    }
    return curr-x;
}
int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int mask=0;mask<(1<<n);mask++){
        int sum = 0 ;
        for(int i=0;i<n;i++){
            if ( (1<<i) & mask ){
                sum = sum + v[i];
            }
            else sum  = sum - v[i];
        }
        if ( (sum % 360 + 360 )%360 == 0 ) {
            cout << "YES" << endl;
            return 0 ;
        }
    }
    cout << "NO" << endl;
    return 0 ;
}
