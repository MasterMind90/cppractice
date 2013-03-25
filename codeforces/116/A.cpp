#include <iostream>
using namespace std;
int main(){
    int T,a,b,total=0;
    int max=0;
    cin >> T;
    while(T--){
        cin >> a >> b;
        total-=a;
        total+=b;
        if (total>max)max=total;
    }
    cout << max << endl;
    return 0;
}
