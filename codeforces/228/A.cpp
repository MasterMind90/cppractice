#include <iostream>
#include <set>
using namespace std;
set<int> s;
int num;
int main(){
    for(int i=0;i<4;i++){cin >> num;s.insert(num);}
    cout << 4-s.size() << endl;
    return 0;
}
