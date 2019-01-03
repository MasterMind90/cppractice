#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    int ones = 0 ;
    int two = 0 ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        if ( x == 1 ) ones++ ;
        else two++;
    }
    if ( ones >= two ) {
        int ans = two ;
        ones -= two;
        ans += ones/3;
        cout << ans << endl;
    }
    else{
        cout << ones << endl;
    }



    return 0 ;
}
