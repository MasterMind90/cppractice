#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x , y ;
    cin >> x >> y ;
    int cnt = 0 ;
    for(long long i=x;;i+=i){
        if ( i <= y ) cnt++;
        else break;
    }
    cout << cnt << endl;

    return 0 ;
}
