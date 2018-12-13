#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin;
    cin.open("input.txt");
    ofstream cout;
    cout.open("output.txt");
    int n ;
    cin >> n ;
    map<int,vector<int> > m ;
    for(int i=0;i<2*n;i++){
        int x ;
        cin >> x ;
        m[x].push_back(i+1);
    }
    for(auto p : m){
        if ( p.second.size() % 2 == 1 ){
            cout << -1 << endl;
            return 0 ;
        }
    }
    for(auto p : m ){
        for(int i=0;i<p.second.size()-1;i+=2){
            cout << p.second[i] << " " << p.second[i+1] << endl;
        }
    }
    return 0 ;
}
