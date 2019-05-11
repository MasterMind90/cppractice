#include <bits/stdc++.h>
using namespace std;
int get(int x){
    int ans = 0 ;
    while(x!=0){
        ans += x%10 ;
        x/=10;
    }
    return ans ;
}
int main(){
    int n , a , b ;
    cin >> n >> a >> b ;
    long long ans = 0 ;
    for(int i=1;i<=n;i++){
        int x = get(i);
        if ( x >= a && x <= b ){
            ans += i ;
        }
    }
    cout << ans << endl;


    return 0 ;
}
