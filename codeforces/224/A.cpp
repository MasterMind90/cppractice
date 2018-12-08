#include <bits/stdc++.h>
using namespace std;
int main(){
    int z , x , y ;
    cin >> z >> x >> y ;
    int b = x*y/z;
    b = sqrt(b);
    int a = x/b;
    int c = y/b;
    int ans = a*4+b*4+c*4 ;
    cout << ans << endl;
    return 0 ;
}
