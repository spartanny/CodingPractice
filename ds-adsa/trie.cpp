#include<bits/stdc++.h>
using namespace std;

struct tNode {
	struct tNode *child[26];
	int weight;
	bool end;
};

struct tNode * getNode(){
	struct tNode * temp = new tNode;
	for(int i=0;i<26;i++){
		temp->child[i] = nullptr;
	}
	temp->weight = -1;
	temp->end = false;
	return temp;
}

void insert(struct tNode *root,string s,int weight){
    struct tNode *curr = root;
    int index;
    for(auto c:s){
        index = c-'a';
        if(!curr->child[index]){
            curr->child[index] = getNode();
        }
        curr = curr->child[index];
        curr->weight = max(weight,curr->weight);
    }
    curr->end = true;
}

int fetch(struct tNode *root, string s){

    struct tNode *temp = root;
    int result = -1;
    for(auto c: s){
        if(!temp->child[c-'a']) return -1;
        temp = temp->child[c-'a'];
    }
    result = max(result,temp->weight);
    return result;
}

int main(){
	int n,q;
	cin>>n>>q;
	vector<pair<string,int>> data;
    vector<string> query;
	struct tNode *root = getNode();
	for(int i=0;i<n;i++){
		string s;int w;
		cin>>s>>w;
		insert(root,s,w);
	}
	for(int i=0;i<q;i++){
		string s;cin>>s;
        cout<<fetch(root,s)<<endl;
	}
}