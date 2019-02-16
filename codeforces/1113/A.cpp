#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , v ; 
    cin >> n >> v ;
    int liters = min(n-1,v)  ; 
    int cost = liters;
    for(int i=2;i<=n;i++){
        liters--;
        int r = n - i ;
        if ( r > liters ) {
            liters++;
            cost+=i;
        }
    }
    cout << cost << endl;
    return 0 ; 
}
