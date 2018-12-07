#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<int> v(n) ;
    queue<pair<int,int> > q ;
    for(int i=0;i<n;i++){
        cin >> v[i];
        q.push({v[i],i+1});
    }
    while(!q.empty()){
        if ( q.size() == 1 ) {
            cout << q.front().second << endl;
            return 0 ;
        }
        auto p = q.front() ; q.pop();
        p.first -= m ;
        if ( p.first > 0 ) q.push(p);
    }
    return 0 ;
}
