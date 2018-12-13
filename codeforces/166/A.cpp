#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> &p1,pair<int,int> &p2){
    if ( p1.first > p2.first ) return true ;
    else if ( p1.first == p2.first ){
        return p1.second < p2.second ;
    }
    return false ;
}
int main(){
    int n , k ;
    cin >> n >> k ;
    k--;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second ;
    }
    sort(v.begin(),v.end(),comp);
    pair<int,int> &target = v[k];
    int c = 0 ;
    for(int i=k-1;i>=0;i--){
        if ( v[i].first == target.first && v[i].second == target.second ) c++;
        else break;
    }
    for(int i=k+1;k<n;i++){
        if ( v[i].first == target.first && v[i].second == target.second ) c++ ;
        else break ;
    }
    cout << c+1 << endl;
    return 0 ;
}
