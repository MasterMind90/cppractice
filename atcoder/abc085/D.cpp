#include <bits/stdc++.h>

using namespace std;

int main(){
    int n , H ;
    cin >> n >> H ;
    vector<int> a(n) , b(n) ;
    int nax = 0 ;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        nax = max(nax, a[i]) ;
    }
    priority_queue<int> q ;
    for(int i = 0; i < n; i++){
        if ( b[i] >= nax ) q.push(b[i]) ;
    }
    int ans = 0 ;
    while(not q.empty() && H > 0){
        H -= q.top() ; q.pop() ;
        ans++;
    }
    if ( H > 0 ){
        ans += (H + nax - 1) / nax ;
    }
    cout << ans << endl;

    return 0 ;
}
