#include <iostream>
using namespace std;
int gcd(int a, int b){
    if (b>a){
        int tmp=a;
        a=b;
        b=tmp;
    }
    if (b==0) return a;
    gcd(b,a%b);
}
int main(){
    int a,b,n;
    cin >> a >> b >> n;
    int i=1;
    while(true){
        if (i%2==1){
            n = n - gcd(a,n);
            i++;
            if (n<0){
                cout << 1 << endl;
                return 0;
            }
        }
        else{
            n = n - gcd(b,n);
            i++;
            if (n<0){
                cout << 0 << endl;
                return 0;
            }
        }
    }

    return 0;
}
