#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5 ;

int n , m ;
int mark[3][N] ;
multiset<pair<pair<int,int>, pair<int,int> > > blocked ;

void lock(int x, int y){
    int c = 0 ;
    if ( x == 1 ) c = 1 ;
    else c = -1;
    for(int i = -1; i <= 1; i++){
        if ( mark[x + c][y + i] ) {
            blocked.insert(make_pair(make_pair(x, y), make_pair(x + c, y + i) ));
            blocked.insert(make_pair(make_pair(x + c, y + i), make_pair(x, y)  ));
        }
    }
}
void unlock(int x, int y){
    int c = 0 ;
    if ( x == 1 ) c = 1 ;
    else c = -1;
    for(int i = -1; i <= 1; i++){
        if ( mark[x + c][y + i] ) {
            blocked.erase(make_pair(make_pair(x, y), make_pair(x + c, y + i) ));
            blocked.erase(make_pair(make_pair(x + c, y + i), make_pair(x, y)  ));
        }
    }
}

int main(){
    cin >> n >> m ;
    for(int i = 0; i < m; i++){
        int x , y ;
        cin >> x >> y ;
        if ( mark[x][y] == false ){
            mark[x][y] = true ;
            lock(x, y);
        }
        else{
            mark[x][y] = false ;
            unlock(x, y) ;
        }
        if ( blocked.empty() ){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;

    }


    return 0 ;
}
