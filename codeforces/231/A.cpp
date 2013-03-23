#include <iostream>
using namespace std;

int main(){
    int a,b,c,n;
    cin >> n;

    int counter=0;
    while(n--){
        int count=0;
        cin >> a >> b >> c;
        if (a==1)count++;
        if (b==1)count++;
        if (c==1)count++;
        if (count>=2)counter++;
    }
    cout << counter << endl;
    return 0;
}
