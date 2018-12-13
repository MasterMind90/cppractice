#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    int x25 = 0 ;
    int x50 = 0 ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        if ( x == 25 ) x25++ ;
        else if ( x == 50 && x25 >= 1 ) {
            x50++;
            x25--;
        }
        else if ( x == 100 ){
            if ( x50 >= 1 && x25 >= 1 ){
                x50--;
                x25--;
            }
            else if ( x25 >= 3 ){
                x25-=3;
            }
            else{
                cout << "NO" << endl;
                return 0 ;
            }
        }
        else{
            cout << "NO" << endl;
            return 0 ;
        }
    }
    cout << "YES" << endl;
    return 0 ;
}
