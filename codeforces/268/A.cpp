#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    vector<int> v1,v2;

    cin >> n;
    int a,b;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }

    int count=0;
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            if ( v1[i]==v2[j])count++;
        }
    }

    cout << count << endl;


    return 0;
}
