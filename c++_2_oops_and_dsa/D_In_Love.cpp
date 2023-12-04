#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    // int lowerR , highestL;
    // lowerR = INT_MAX;
    set<pair<int,int>> s;
    cin.ignore();
    while(q--){
        string str;
        getline(cin , str);
        char op = str[0];
        string l = "";
        int x = 2;
        while(str[x] != ' '){
            l+=str[x++];
        }
        x++;
        string r = "";
        while(str[x] != '\0'){
            r += str[x++];
        }

        int li = stoi(l);
        int ri = stoi(r);
        // addition
        if(op == '+'){
            s.insert({li,ri});
        } else{
            // removal
            
        }
    }
}