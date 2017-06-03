#include <fstream>
#include <iostream>
using namespace std;

void divide(ofstream &m3,ofstream & m1 , ofstream &k100 , ofstream &k1 ,int random ,int line ,char t){
		m3 << t;
		if (random==0 && line<3000000){//if I want get 1m lines , I need to compare 3m
				m1 << t;
				if (line<300000)//also if I want get 100k lines , I need to compare 300k
					k100 << t;
				if (line<3000)
					k1 << t;
			}
}
void cleartext(ifstream &infile)
{
	
	ofstream out3m("AOL3M.txt");
	ofstream out1m("AOL1M.txt");
	ofstream out100k("AOL100K.txt");
	ofstream out1k("AOL1K.txt");	
	int number_of_lines=0,random; // random is a number which is using for getting random line
	char token;
	bool prev;
	while (infile.get(token)){					
		random = number_of_lines%3;// I can only use 2 or 3 for it because I have only 3.5m lines so when I used 4 ,I cant get 1m lines.   
		if (isalnum(token)){
			prev = true;// this is control the previous character for me 
			token = tolower(token);			
			divide(out3m,out1m,out100k,out1k,random,number_of_lines,token);
		}		
		else if (token == ' '){// I need also space character for clearing
			divide(out3m,out1m,out100k,out1k,random,number_of_lines,token);
		}
		else if (token == '\n'&& prev==true){// I checked '\n' for end of line 
			prev= false;	// I only get '\n' if prev. char. is alphanumeric.		
			number_of_lines++;			
			divide(out3m,out1m,out100k,out1k,random,number_of_lines,token);
		}
	}
}

