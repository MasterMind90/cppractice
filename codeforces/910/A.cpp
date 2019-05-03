#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , d ;
    cin >> n >> d ;
    string s ;
    cin >> s ;
    int cur = 0 ;
    int ans = 0 ;
    queue<int> q ;
    q.push(cur);
    while(q.size()){
        int f = q.front(); q.pop();
        for(int i=min(f+d,n-1);i>f;i--){
            if ( s[i] == '1' ){
                q.push(i);
                cur = i ;
                ans++;
                break;
            }
        }
    }
    if ( cur == n-1 ) {
        cout << ans << endl;
    }
    else cout << -1 << endl;
    return 0 ;
}
