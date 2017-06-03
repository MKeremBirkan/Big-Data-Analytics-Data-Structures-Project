#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void divide (ifstream &file){
	ofstream out1("out1.txt");
	ofstream out2("out2.txt");
	ofstream out3("out3.txt");
	ofstream out4("out4.txt");
	string t; // token
	int count =0;
	while (getline(file,t)){
		if (count < 1000000)
			out1 << t<< endl;
		else if (1000000 <= count && count<2000000 )
			out2 << t << endl;
		else if (2000000 <= count && count<3000000 )
			out3 << t << endl;
		else if (3000000 <= count)
			out4 << t << endl;	
		count++;	
	}
			
}
void merge(ifstream &read1,ifstream &read2, ofstream &write){
	
	string line1;
	string line2;

	getline(read1,line1);
	getline(read2,line2); 

	while ((!read1.eof()) || (!read2.eof()))
	{		 
		if((!read1.eof()) && (!read2.eof())){
			if (line1 < line2){
				write << line1<<endl;
				getline ( read1,line1);
				while(line1==line2){
					getline(read1,line1);
				}	
			}
	
			else if (line1 > line2){
				write << line2 << endl;	
 				getline ( read2, line2);
				while(line2==line1){
					getline(read2,line2);
				}		
			}
		}
		if(read2.eof()){
			write << line1<<endl;
			getline ( read1, line1);
			write << line1<<endl;
		}
		if(read1.eof()){
			write << line2 <<endl;
			getline ( read2, line2);
			write << line2 <<endl;
		}
	}

}
 	
 	
