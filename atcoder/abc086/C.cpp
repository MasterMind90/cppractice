#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    int curx = 0 , cury = 0 ;
    int curt = 0 ;
    for(int i=0;i<n;i++){
        int t , x , y ;
        cin >> t >> x >> y ;
        int dist = abs(curx-x) + abs(cury-y);
        if ( dist <= t-curt ){
            if ( dist % 2 != (t-curt)%2 ){
                cout << "No" << endl;
                return 0 ;
            }
            curx = x ;
            cury = y ;
            curt = t ;
        }
        else {
            cout << "No" << endl;
            return 0 ;
        }
    }
    cout << "Yes" << endl;
    return 0 ;
}
