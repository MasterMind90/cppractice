#include <bits/stdc++.h>
using namespace std;

int main(){
    int a , b , x ;
    cin >> a >> b >> x ;
    string ans = "" ;
    if ( a >= b ) {
        ans += "0" ;
        a--;
        bool f = true ;
        for(int i=0;i<x-1;i++){
            if ( f ){
                if ( b > 0 ) {
                    ans += "1" ;
                    b--;
                }
                f = false ;
            }
            else{
                if ( a > 0 ) {
                    ans += "0" ;
                    a--;
                }
                f = true ;
            }
        }
        char c = ans[ans.size()-1] ;
        if ( c == '0' ){
            for(int i=0;i<a;i++){
                ans += "0" ;
            }
            for(int i=0;i<b;i++){
                ans += "1" ;
            }
        }
        else{
            for(int i=0;i<b;i++){
                ans += "1" ;
            }
            for(int i=0;i<a;i++){
                ans += "0" ;
            }
        }
    }
    else {
        ans += "1" ;
        b--;
        bool f = true ;
        for(int i=0;i<x-1;i++){
            if ( f ){
                if ( a > 0 ) {
                    ans += "0" ;
                    a--;
                }
                f = false ;
            }
            else{
                if ( b > 0 ) {
                    ans += "1" ;
                    b--;
                }
                f = true ;
            }
        }
        char c = ans[ans.size()-1] ;
        if ( c == '0' ){
            for(int i=0;i<a;i++){
                ans += "0" ;
            }
            for(int i=0;i<b;i++){
                ans += "1" ;
            }
        }
        else{
            for(int i=0;i<b;i++){
                ans += "1" ;
            }
            for(int i=0;i<a;i++){
                ans += "0" ;
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}
