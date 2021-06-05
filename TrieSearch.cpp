#include<bits/stdc++.h>
using namespace std;
//Node class which will contain map data structure for pointing towards various nodes...
class Node{
	public:
		char ch;
		unordered_map<char, Node*> m;
		bool terminal;
		Node(char character){
			ch = character;
			terminal = false;
		}
};
//Creating Trie class which will contain all the methods of Trie object and a root pointer which will point to the nodes..
class Trie{
private:
	Node* root;
public:
	Trie(){
		root = new Node('\0');
	}
	void insert(char* w){
		Node* temp = root;
		for(int i=0;w[i]!='\0';i++){
			char ch = w[i];
			if(temp->m.count(ch) == 0){
				//It means that the partcular character is not present in the string or in the list..
				Node* n = new Node(ch);
				temp->m[ch] = n;
			}
			temp = temp->m[ch];
		}
		temp->terminal = true;
	}
	bool is_present(char* w){
		Node* temp = root;
		for(int i=0;w[i]!='\0';i++){
			char ch = w[i];
			if(temp->m.count(ch) == 0){
				return false;
			}
			temp = temp->m[ch];
		}
		return temp->terminal;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Trie t;
	//The Trie object has been created which has the root pointer pointing to the Node object..
	//Now, we will insert the string into the trie data structure..
	t.insert("munish");
	t.insert("kumar");
	t.insert("manoj");
	t.insert("akshay");
	t.insert("amit");
	if(t.is_present("Amit")){
		cout<<"The particular string is present the list."<<endl;
	}
	else{
		cout<<"The particular string is not present in the list."<<endl;
	}
	return 0;
}