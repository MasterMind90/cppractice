#include <iostream>
#include <stack>
#include <vector>

using namespace std;
stack <string> s;
vector <string> v;
int breakdown(string str){
    //cout << "test1" << endl;
    v.clear();
    for(int i=str.length()-1;i>2;i--){
        if (str[i]=='/')
        {
            v.push_back(str.substr(i+1));
            str = str.substr(0,i);
        }
    }

    for(int i=v.size()-1;i>=0;i--) {
        if (v[i]=="..")s.pop();
        else s.push(v[i]);
    }

    v.clear();
    return 1;
}

void s_clear(){
    while(!s.empty())s.pop();
}

void display(){
    v.clear();
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    for(int i=v.size()-1;i>=0;i--){
        cout << "/" << v[i];
        s.push(v[i]);
    }
    cout << "/" << endl;
}

int main(){
    int L;
    cin >> L;
    cin.ignore();
    string str="";
    for(int i=0;i<L;i++){
        getline(cin,str);
        //cin.ignore();
        if (str[0]=='c'){
            if( str[3]=='/'){
                s_clear();
                breakdown(str);
            }
            else{
                str.insert(3,"/");
                breakdown(str);
            }
        }
        else if (str[0]=='p'){
            display();
        }
    }
    return 0;
}