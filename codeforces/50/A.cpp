#include <iostream>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    int hi = h/2;
    int wi = w;
    if (hi==0){
        wi = w/2;
        cout << wi << endl;
        return 0;
    }
    cout << (hi*wi)+ (h%2)*(w/2) << endl;
    return 0;
}
