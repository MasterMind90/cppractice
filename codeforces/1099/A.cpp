#include <bits/stdc++.h>
using namespace std;

int main(){
    long long w , h ;
    cin >> w >> h ;
    long long w1,w2,h1,h2 ;
    cin >> w1 >> h1 ;
    cin >> w2 >> h2 ;
    long long sum = w;
    for(int i=h;i>=0;i--){
        sum += i ;
        if (  i == h1 ){
            sum -= w1 ;
        }
        else if ( i == h2 ) {
            sum -= w2 ;
        }

        if ( sum < 0 ) sum = 0 ;
    }
    cout << sum << endl;
    return 0 ;
}
