#include <iostream>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    for(int i=1; i<(n-k);i++) cout << i << " ";
    int temp=k+1;
    for(int i=n;temp--;i--) cout << i << " " ;
    cout << endl;
    return 0;
}
