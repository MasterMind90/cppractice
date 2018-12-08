#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int MIN = 2000 ;
    int index1 = 0 ;
    int index2 = 0 ;
    for(int i=0;i<n-1;i++){
        int x = v[i]-v[i+1];
        x = abs(x);
        if ( x < MIN ){
            index1 = i ;
            index2 = i+1;
            MIN = x ;
        }
    }
    int x = v[0]-v[n-1];
    x = abs(x) ;
    if ( x < MIN ) {
        index1 = 0 ;
        index2 = n-1;
    }
    cout << index1+1 << " " << index2+1 << endl;
    return 0 ;
}
