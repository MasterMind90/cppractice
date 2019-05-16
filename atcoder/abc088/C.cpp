#include <bits/stdc++.h>
using namespace std;

int main(){
    int ar[4][4] ;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin >> ar[i][j] ;
        }
    }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            for(int k=0;k<=100;k++){
                int b[4] ;
                int a[4] ;
                a[1] = i ;
                a[2] = j ;
                a[3] = k ;
                b[1] = ar[1][1] - i ;
                b[2] = ar[1][2] - i ;
                b[3] = ar[1][3] - i ;
                int ok = true ;
                for(int u=1;u<4;u++){
                    for(int e=1;e<4;e++){
                        if ( a[u]+b[e] != ar[u][e] ){
                            ok = false ;
                        }
                    }
                }
                if ( ok ) {
                    cout << "Yes" << endl;
                    return 0 ;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0 ;
}
