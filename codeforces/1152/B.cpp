#include <bits/stdc++.h>
using namespace std;
bool ok(int x){
    for(int i=0;i<=30;i++){
        if ( x == (1<<i)-1 ) return true ;
    }
    return false ;
}
int main(){
    int x ;
    cin >> x ;
    int ans = 0 ;
    vector<int> v ;
    int turn = 0 ;
    while(!ok(x)){
        if ( turn & 1 ){
            x = x + 1 ;
        }
        else{
            int last = 0 ;
            for(int i=0;i<=30;i++){
                if ( x & (1<<i) ){
                    last = i ;
                }
            }
            for(int i=last;i>=0;i--){
                if ( (x&(1<<i)) == 0 ){
                    last = i ;
                    break;
                }
            }
            last++;
            v.push_back(last);
            last = (1<<last) - 1 ;
            x = x ^ last ;
        }
        ans++;
        turn++;
    }
    cout << ans << endl;
    for(int i=0;i<v.size();i++){
        cout << v[i] << " " ;
    }
    cout << endl;
    return 0 ;
}
