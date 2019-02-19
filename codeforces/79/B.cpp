#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m , k , q ;
    cin >> n >> m >> k >> q ;
    map<pair<int,int>,bool> waste ;
    map<int,set<int> > rowWaste ;
    for(int i=0;i<k;i++){
        int x , y ;
        cin >> x >> y ;
        waste[{x,y}] = true ;
        rowWaste[x].insert(y);
    }
    int sum[4*10005];
    memset(sum,0,sizeof sum);
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1] + (m-(int)rowWaste[i].size());
    }
    for(int i=0;i<q;i++){
        int x , y ;
        cin >> x >> y ;
        if ( waste[{x,y}] ){
            cout << "Waste" << endl;
        }
        else{
            int ans = sum[x-1];
            int cnt = 0 ;
            for(int c : rowWaste[x]){
                if ( c < y ) cnt++;
                else break;
            }
            ans += y-cnt ;
            if ( ans % 3 == 1 ){
                cout << "Carrots" << endl;
            }
            else if ( ans % 3 == 2 ) {
                cout << "Kiwis" << endl;
            }
            else {
                cout << "Grapes" << endl;
            }
        }
    }
    return 0 ;
}
