#include <stdio.h>
#include <algorithm>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>  
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <sstream> 
#include <bitset>
#include <unordered_map>


using namespace std;



int main(int argc, char* argv[]){

	ifstream infile(argv[1]);

	string line = "";
	
	unordered_map<int, int> table;
	//cout<<"11111111111111"<<endl;
	while (getline(infile, line)){
		istringstream iss (line);
		int asc;
		iss >> asc;
		int huffcode;
		iss>> huffcode;
		//pq.push(new Node(asc,fre,0,0));
		table[huffcode]=asc;
	}
	//cout<<"11111111111111"<<endl;
	string res ="";
	char c;
	while( cin.get(c)){
		res=res+bitset<8>(c).to_string();
	}
	
	string tail= res.substr(res.size()-16);
	int validBits= stoi(tail.substr(13),nullptr,2);
	res = res.substr(0, res.size()-16);
	res = res+ tail.substr(0,validBits);

	//cout << to_string(table[101])<<endl;


	for(int i=0; i<res.size()-1; i++){
		for(int j=3; j<=6; j++){
			string str = res.substr(i,j);
			if(table.find(stoi(str)) != table.end()){
				cout<< (char)(table[stoi(str)]);
				i=i+j;
				break;
			}
		}
	}





	/*
	while(res.size()!=0){
		for(int i=3; i<=6; i++){
			string key = res.substr(0,i);
			if(table.find(key) != table.end()){
				cout<<(char)table[key];
				if(key.size()!=res.size()){
					res=res.substr(i);
				}
	
			}
		}
	}
	*/



	/*
	while(res.size()>5){
		for(int i=3; i<=6; i++){
			string key = res.substr(0,i);
			if(table.find(key) != table.end()){
				cout<<table[key];
				res=res.substr(i);
			}
		}
	}
]
	res=res+ tail.substr(0,validBits);
	
	while(res.size()>2){
		for(int i=3; i<=6; i++){
			string key = res.substr(0,i);
			if(table.find(key) != table.end()){
				cout<<table[key];
				res=res.substr(i);
			}
		}
	}
	*/
	


	return 0;
}