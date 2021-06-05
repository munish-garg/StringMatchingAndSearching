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
	void insert(string s){
		Node* temp = root;
		for(int i=0;i<s.size();i++){
			char ch = s[i];
			if(temp->m.count(ch) == 0){
				//It means that the partcular character is not present in the string or in the list..
				Node* n = new Node(ch);
				temp->m[ch] = n;
			}
			temp = temp->m[ch];
		}
	}
	bool is_present(string pat){
		Node* temp = root;
		for(int i=0;i<pat.size();i++){
			char ch = pat[i];
			if(temp->m.count(ch) == 0){
				return false;
			}
			temp = temp->m[ch];
		}
		return true;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	//We will take input as string and pattern to check whether the pattern is the substring of the particular string or not...
	string s;
	cin>>s;
	Trie t;
	for(int i=0;i<s.size();i++){
		t.insert(s.substr(i));
	}	
	//In this way all the successive substrings from every index till the end will be added to the trie..
	string pat; cin>>pat;
	if(t.is_present(pat)){
		cout<<"The particular substring is present in the main string."<<endl;
	}
	else{
		cout<<"The particular substring is not present in the main string."<<endl;
	}
	return 0;
}