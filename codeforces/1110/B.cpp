#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m , k ; 
    cin >> n >> m >> k ; 
    vector<int> v(n) ;
    vector<int> t ; 
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int total = (v[v.size()-1] - v[0]) + 1;
    for(int i=1;i<n;i++){
        t.push_back(v[i]-v[i-1]-1);
    }
    sort(t.rbegin(),t.rend());
    int cut = 1 ; 
    int ptr = 0 ; 
    while(cut<k){
        total -= t[ptr++] ; 
        cut++;
    }
    cout << total << endl;
    return 0 ; 
}
