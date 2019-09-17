#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code
    map<char,int> m;
    map<char,int>:: iterator it;
    string s1="aacdb";
    string s2="gafd";
    for(int i=0;i<s1.size();i++)
        m[s1[i]]++;
        
    for(int i=0;i<s2.size();i++)
        m[s2[i]]++;
        
        string result="";
        
    for(it=m.begin();it!=m.end();it++)
        if(it->second==1)
            result+=it->first;
            
    cout<<result;
        
}

