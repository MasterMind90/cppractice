#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k ;
    cin >> n >> k ;
    bool ar[10] ;
    for(int i=0;i<10;i++){
        ar[i] = true ;
    }
    for(int i=0;i<k;i++){
        int x ;
        cin >> x ;
        ar[x] = false ;
    }
    for(int i=n;;i++){
        int x = i ;
        bool ok = true ;
        while(x!=0){
            if ( ar[x%10] == false ){
                ok = false ;
                break;
            }
            x /= 10 ;
        }
        if ( ok ){
            cout << i << endl;
            break;
        }
    }
    return 0 ;
}
