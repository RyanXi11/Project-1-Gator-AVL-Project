#include <iostream>
#include <sstream>
#include "AVL.h"

using namespace std;

bool isValidName(const string& name){
	for(char c: name){
		if(!isalpha(c) && c != ' '){
			return false;
		}
	}
	return true;
}

bool isValidUfid(const string& ufid){
	if(ufid.length() != 8){
		return false;
	}
	for(char c: ufid){
		if(!isdigit(c)){
			return false;
		}
	}
	return true;
}

int main(){
	AVLTree tree;
	string line;

	getline(cin, line);
	int numCommands = stoi(line);

	for(int i = 0; i < numCommands; i++){
		getline(cin, line);
		stringstream ss(line);
		string command;
		ss >> command;

		if(command == "insert"){
			string dummy, name, ufid;
			getline(ss, dummy, '"');
			getline(ss, name, '"');
			ss >> ufid;

			if(isValidName(name) && isValidUfid(ufid)){
				tree.insert(name, ufid);
			}else{
				cout << "unsuccessful" << endl;
			}
		}else if(command == "remove"){
			string ufid;
			ss >> ufid;
			tree.remove(ufid);
		}else if(command == "search"){
			ss >> ws;
			if(ss.peek() == '"'){
				string dummy, name;
				getline(ss, dummy, '"');
				getline(ss, name, '"');
				tree.searchName(name);
			}else{
				string ufid;
				ss >> ufid;
				tree.searchID(ufid);
			}
		}else if(command == "printInorder"){
			tree.printInorder();
		}else if(command == "printPreorder"){
			tree.printPreorder();
		}else if(command == "printPostorder"){
			tree.printPostorder();
		}else if(command == "printLevelCount"){
			tree.printLevelCount();
		}else if(command == "removeInorder"){
			int N;
			ss >> N;
			tree.removeInorder(N);
		}
	}

	return 0;
}