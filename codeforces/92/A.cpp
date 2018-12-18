#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    long long res = (n*(n+1))/2;

    int x = m % res ;

    for(int i=1;i<=n;i++){
        if ( x >= i ){
            x-=i;
        }
        else{
            cout << x << endl;
            return 0 ;
        }
    }
    cout << x << endl;
    return 0 ;
}
