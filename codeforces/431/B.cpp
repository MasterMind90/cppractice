#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a[6][6] ;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cin >> a[i][j];
        }
    }
    int ar[] = {1,2,3,4,5} ;
    long long ans = ( a[ar[0]][ar[1]] + a[ar[1]][ar[0]] + a[ar[2]][ar[3]] + a[ar[3]][ar[2]] ) ;
    ans+=( a[ar[1]][ar[2]] + a[ar[2]][ar[1]] + a[ar[3]][ar[4]] + a[ar[4]][ar[3]]  ) ;
    ans+=(a[ar[2]][ar[3]] + a[ar[3]][ar[2]] );
    ans+=( a[ar[3]][ar[4]] + a[ar[4]][ar[3]]  );
    long long sum = ans ;
    while(next_permutation(ar,ar+5)){
        long long ans = ( a[ar[0]][ar[1]] + a[ar[1]][ar[0]] + a[ar[2]][ar[3]] + a[ar[3]][ar[2]] ) + ( a[ar[1]][ar[2]] + a[ar[2]][ar[1]] + a[ar[3]][ar[4]] + a[ar[4]][ar[3]]  ) ;
        ans+=(a[ar[2]][ar[3]] + a[ar[3]][ar[2]] );
        ans+=( a[ar[3]][ar[4]] + a[ar[4]][ar[3]]  );
        if ( ans > sum ) {
            sum = ans ;
        }
    }
    cout << sum << endl;
    return 0 ;
}
