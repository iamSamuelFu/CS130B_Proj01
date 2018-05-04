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


void trim(string& s)
{
   size_t p = s.find_first_not_of(" \t");
   s.erase(0, p);

   p = s.find_last_not_of(" \t");
   if (string::npos != p)
      s.erase(p+1);
}


int main(int argc, char* argv[]){

	ifstream infile(argv[1]);

	string line = "";
	
	unordered_map<string, int> table;
	

	while (getline(infile, line)){
		istringstream iss (line);
		int asc;
		iss >> asc;
		string huffcode= line.substr(3);
		trim(huffcode);
		//pq.push(new Node(asc,fre,0,0));
		table[huffcode]=asc;
	}
	

	string res ="";
	char c;
	while( cin.get(c)){
		res=res+bitset<8>(c).to_string();
	}
	


	string tail= res.substr(res.size()-16);
	int validBits= stoi(tail.substr(13),nullptr,2);
	res = res.substr(0, res.size()-16);
	res = res+ tail.substr(0,validBits);

	

/*

	for(int i=0; i<res.size()-1; i++){
		for(int j=3; j<=6; j++){
			string str = res.substr(i,j);
			if(table.find(str) != table.end()){
				cout<< (char)(table[str]);
				i=i+j;
				break;
			}
		}
	}

*/


	while(res.size()!=0){
		for(int i=3; i<=6; i++){
			string key = res.substr(0,i);
			if(table.find(key) != table.end()){
				cout<<(char)table[key];
				if(key.size()!=res.size()){
					res=res.substr(i);
				}else if(key.size()==res.size()){
					res="";
				}
	
			}
		}
	}




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