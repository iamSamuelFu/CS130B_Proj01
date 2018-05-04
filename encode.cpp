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
	unordered_map<int, string> table;
	while (getline(infile, line)){
		istringstream iss (line);
		int asc;
		iss >> asc;
		string huffcode= line.substr(3);
		trim(huffcode);
		//pq.push(new Node(asc,fre,0,0));
		table[asc]=huffcode;
	}
	


	string res="";
	char c;
	while( cin.get(c)){
		if(c==EOF)
			break;
		res=res+table[c];
	}
	
	if(res.size()%8==0){
		res=res+"0000000000000000";
	}else if(res.size()%8==1){
		res=res+"000000000000001";
	}else if(res.size()%8==2){
		res=res+"00000000000010";
	}else if(res.size()%8==3){
		res=res+"0000000000011";
	}else if(res.size()%8==4){
		res=res+"000000000100";
	}else if(res.size()%8==5){
		res=res+"00000000101";
	}else if(res.size()%8==6){
		res=res+"0000000110";
	}else if(res.size()%8==7){
		res=res+"000000111";
	}
	//cout<<res<<endl;


	
	if(res.size()%8==0){
		while(res.size()!=0){
			string sub= res.substr(0,8);
			if(res.size()>8){
				res=res.substr(8);
			}else if(res.size()==8){
				res="";
			}
			bitset<8> bits(sub);
			unsigned long n= bits.to_ulong();
			cout<<static_cast<char>(n);
		}
	}
	
	





	return 0;
}


