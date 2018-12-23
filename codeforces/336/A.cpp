#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x , y ;
    cin >> x >> y ;
    if ( x > 0 && y > 0 ) {
        pair<int,int> p1 = {0,x+y} ;
        pair<int,int> p2 = {x+y,0} ;
        cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
    }
    else if ( x > 0 && y < 0 ) {
        pair<int,int> p1 = {0,y-x} ;
        pair<int,int> p2 = {x+abs(y),0} ;
        if ( p1.first > p2.first ) swap(p1,p2);
        cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
    }
    else if ( x < 0 && y > 0 ) {
        pair<int,int> p1 = {0,y+abs(x)} ;
        pair<int,int> p2 = {x-y,0} ;
        if ( p1.first > p2.first ) swap(p1,p2);
        cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
    }
    else{
        pair<int,int> p1 = {0,x+y} ;
        pair<int,int> p2 = {x+y,0} ;
        if ( p1.first > p2.first ) swap(p1,p2);
        cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
    }
    return 0 ;
}
