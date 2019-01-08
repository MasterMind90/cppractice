#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , h ;
    cin >> n >> h ;
    int twos = 0 ;
    int ones = 0 ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        if ( x > h ) twos+=2;
        else ones++;
    }
    cout << twos+ones << endl;
    return 0 ;
}
