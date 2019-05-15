#include <bits/stdc++.h>
using namespace std;

int main(){
    int ar[] = {8,16,4,15,23,42};
    int ans[6] ;
    cout << "? 1 2" << endl;
    cout << flush ;
    int a ;
    cin >> a ;
    cout << "? 2 3" << endl;
    cout << flush ;
    int b ;
    cin >> b ;
    for(int i=0;i<6;i++){
        if ( a % ar[i] == 0 && b % ar[i] == 0 ){
            int v1 = 0 ;
            for(int j=0;j<6;j++){
                if ( i == j ) continue ;
                if ( ar[i] * ar[j] == a )
                    v1 = ar[j] ;
            }
            int v2 = 0 ;
            for(int j=0;j<6;j++){
                if ( i == j ) continue ;
                if ( ar[i] * ar[j] == b )
                    v2 = ar[j] ;
            }
            if ( v1 && v2 ){
                ans[1] = ar[i];
                ans[0] = v1;
                ans[2] = v2;
                break;
            }
            /*
            if ( a / ar[i] == b / ar[i] ){
                ans[1] = ar[i];
                ans[0] = a/ar[i];
                ans[2] = b/ar[i];
                break;
            }
            */
        }
    }
    cout << "? 4 5" << endl;
    cout << flush ;
    int x ;
    cin >> x ;
    cout << "? 5 6" << endl;
    cout << flush ;
    int y ;
    cin >> y ;
    for(int i=0;i<6;i++){
        if ( x % ar[i] == 0 && y % ar[i] == 0 ){
            int v1 = 0 ;
            for(int j=0;j<6;j++){
                if ( i == j ) continue ;
                if ( ar[i] * ar[j] == x )
                    v1 = ar[j] ;
            }
            int v2 = 0 ;
            for(int j=0;j<6;j++){
                if ( i == j ) continue ;
                if ( ar[i] * ar[j] == y )
                    v2 = ar[j] ;
            }
            if ( v1 && v2 ){
                ans[4] = ar[i];
                ans[3] = v1;
                ans[5] = v2;
                break;
            }
            /*
            if ( x / ar[i] == y )
            ans[4] = ar[i];
            ans[3] = x/ar[i];
            ans[5] = y/ar[i];
            break;
            */
        }
    }
    cout << "!";
    for(int i=0;i<6;i++){
        cout << ' ' << ans[i];
    }
    cout << endl;
    cout << flush ;
    return 0 ;
}
