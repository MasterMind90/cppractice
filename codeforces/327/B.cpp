#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000000 + 1 ;
int primes[MAX] ;
int main(){
    primes[0]=1;
    primes[1]=1;
    vector<int> p ;
    for(int i=2;i<MAX;i++){
        if ( primes[i] == 0 ){
            p.push_back(i);
            for(int j=i+i;j<MAX;j+=i){
                primes[j] = 1 ;
            }
        }
    }
    int n ;
    cin >> n ;
    for(int i=0;i<n;i++){
        cout << p[i] << " " ;
    }
    cout << endl;

    return 0 ;
}
