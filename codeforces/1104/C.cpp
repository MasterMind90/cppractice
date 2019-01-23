#include <bits/stdc++.h>
using namespace std;

int main(){
    string x ;
    cin >> x ;
    bool h[4] ;
    bool v ;
    for(int i=0;i<x.size();i++){
        if ( x[i] == '0' ){
            if ( v == false ) {
                v = true;
                cout << 1 << " " << 1 << endl;
            }
            else{
                cout << 3 << " " << 1 << endl;
                v=false;
            }
        }
        else{
            bool f = false ;
            for(int i=0;i<4;i++){
                if ( h[i] == false ) {
                    cout << i+1 << " " << 3 << endl;
                    h[i] = true ;
                    f = true;
                    break;
                }
            }
            if ( !f ){
                cout << 1 << " " << 3 << endl;
                for(int i=1;i<4;i++) h[i]=false;
            }
        }
    }
    return 0 ;
}
