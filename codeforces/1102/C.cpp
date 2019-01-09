#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , x , y ;
    cin >> n >> x >> y ;
    priority_queue<int, vector<int> , greater<int> > q ;
    for(int i=0;i<n;i++){
        int p ;
        cin >> p ;
        q.push(p);
    }
    if ( y >= x ){
        int ans = 0 ;
        while ( (q.size() > 0) && (q.top() - x <= 0) ){
            q.pop();
            ans++;
            if ( q.size() > 0 ){
                int c = q.top()+y;
                q.pop();
                q.push(c);
            }
        }
        cout << ans << endl;
        return 0 ;
    }
    else{
        cout << n << endl;
    }

    return 0 ;
}
