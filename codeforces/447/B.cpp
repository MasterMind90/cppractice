#include <bits/stdc++.h>
using namespace std;

int main(){
    string x ;
    cin >> x ;
    int k ;
    cin >> k ;
    vector<int> v(26);
    for(int i=0;i<26;i++){
        cin >> v[i];
    }
    int val = *max_element(v.begin(),v.end());
    long long sum = 0LL ;
    int i ;
    for(i=0;i<x.size();i++){
        sum += ((i+1)*v[x[i]-'a']);
    }
    for(;i<x.size()+k;i++){
        sum += ((i+1)*val);
    }
    cout << sum << endl;
    return 0 ;
}
