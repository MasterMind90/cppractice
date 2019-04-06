#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    int A[n][m] ;
    int B[n][m] ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j] ;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> B[i][j] ;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if ( A[i][j] != B[i][j] ){
                if ( i+1 == n || j+1 == m ){
                    cout << "NO" << endl;
                    return 0;
                }
                A[i][j] = !A[i][j] ;
                A[i+1][j] = !A[i+1][j] ;
                A[i][j+1] = !A[i][j+1];
                A[i+1][j+1] = !A[i+1][j+1];
            }

        }
    }
    cout << "YES" << endl;
    return 0 ;
}
