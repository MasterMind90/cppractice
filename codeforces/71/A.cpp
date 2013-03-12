#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<string> v;
    int n;
    cin >> n;
    cin.ignore();
    string str;
    for(int i=0;i<n;i++){
        getline(cin,str);
        v.push_back(str);
    }
    for(int i=0;i<v.size();i++)
        if (v[i].length()>10)
            cout << v[i][0] << v[i].length()-2 << v[i][v[i].length()-1] << endl;
        else cout << v[i] << endl;

    return 0;
}
