#include <bits/stdc++.h>
using namespace std;

double d(pair<int,int> start, pair<int,int> dest){
    int x = start.first ; 
    int y = start.second ; 
    int xx = dest.first ; 
    int yy = dest.second ; 
    return sqrt( (x-xx)*(x-xx) + (y-yy)*(y-yy) );
}

int main(){
    int n , k ; 
    cin >> n >> k ; 
    vector<pair<int,int> > v(n) ; 
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second ; 
    }
    double sum = 0 ; 
    for(int i=1;i<n;i++){
        double dist = d(v[i],v[i-1]);
        sum += dist/50.0 ; 
    }
    sum = sum * k ; 
    cout << fixed << setprecision(9) << sum << endl;
    return 0 ; 
}
