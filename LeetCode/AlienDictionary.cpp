#include<bits/stdc++.h>
using namespace std;

map<char,int> ordering;

bool comparator(string a,string b){
    int i=0,j=0;
    while(i<a.length() and j<b.length()){
            if(ordering[a[i]] == ordering[b[j]])
                i++,j++;
            else if(ordering[a[i]] < ordering[b[j]])
                return true;
            else    return false;
    }
    return (a.length() <= b.length());
}

int main(){
    vector<string> words = {"aaa", "abcd", "adca", "cab", "cad"};
    vector<char> order = {'b', 'd', 'a', 'c'};
    
    for(int i=0;i<order.size();i++){
        ordering[order[i]] = i;
    }
    sort(words.begin(),words.end(),comparator);
    for(auto word : words)
        cout<<word<<" ";
}