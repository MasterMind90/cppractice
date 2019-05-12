#include <bits/stdc++.h>
using namespace std;

int main(){
    int w , h , n ;
    cin >> w >> h >> n ;
    int a , b ;
    a = b = 0 ;
    for(int i=0;i<n;i++){
        int x , y , t ;
        cin >> x >> y >> t ;
        if ( t == 1 ){
            a = max(a,x);
        }
        else if ( t == 2 ){
            w = min(w,x);
        }
        else if ( t == 3 ){
            b = max(b,y);
        }
        else{
            h = min(h,y);
        }
    }
    if ( a >= w || b >= h ){
        cout << 0 << endl;
    }
    else{
        cout << (w-a)*(h-b) << endl;
    }
    return 0 ;
}
