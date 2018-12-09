#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    int count100 = 0 ;
    int count200 = 0 ;
    for(int i=0;i<n;i++){
        int x;
        cin >> x ;
        if ( x == 100 ) count100++ ;
        else count200++;
    }
    if ( count200 % 2 == 1 ){
        if ( count100 < 2 ){
            cout << "NO" << endl;
            return 0 ;
        }
        else count100-=2;
    }
    if ( count100 % 2 == 1 ){
        cout << "NO" << endl;
        return 0 ;
    }
    cout << "YES" << endl;

    return 0 ;
}
