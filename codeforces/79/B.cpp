#include <bits/stdc++.h>
using namespace std;

int main(){
    string ans[] = {"Grapes","Carrots","Kiwis"};
    int n , m , w , q ;
    cin >> n >> m >> w >> q;
    map<pair<int,int>,bool> waste ;
    map<int,vector<int> > row ;
    for(int i=0;i<w;i++){
        int x , y  ;
        cin >> x >> y ;
        row[x].push_back(y);
        waste[{x,y}] = true ;
    }
    vector<int> sum(n+1,0);
    for(auto &p : row){
        sum[p.first] = p.second.size();
        sort(p.second.begin(),p.second.end());
    }
    for(int i=1;i<=n;i++){
        sum[i]+=sum[i-1];
    }
    while(q--){
        int x , y ;
        cin >> x >> y ;
        if ( waste[{x,y}] ){
            cout << "Waste" << endl;
        }
        else{
            int wst = sum[x-1];
            int index = lower_bound(row[x].begin(),row[x].end(),y) - row[x].begin();
            wst+=index;
            int total = (x-1)*m + y ;
            total-=wst ;
            cout << ans[total%3] << endl;
        }
    }
    return 0 ;
}
