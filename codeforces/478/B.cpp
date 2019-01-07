#include <bits/stdc++.h>
using namespace std;

long long teams(long long x){
    return (x*(x+1LL))/2LL;
}

int main(){
    long long n , m;
    cin >> n >> m ;
    long long r = n % m ;
    long long MIN = (m-r)*teams(n/m-1LL)+r*teams(n/m);
    long long MAX = teams((n-(m-1LL))-1LL);
    cout << MIN << " " << MAX << endl;
    return 0 ;
}
