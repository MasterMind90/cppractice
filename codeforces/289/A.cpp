#include <iostream>
using namespace std;
long long n,k;
long long l[100001];
long long r[100001];
long long v;
int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> l[i] >> r[i];
        v+=(r[i]-l[i])+1;
    }
    //cout << v << endl;
    cout << (k-(v%k))%k << endl;
    return 0;
}
/*
4 19
1 3
5 5
6 6
8 10
*/
