#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <time.h>
#include "clear.h"
#include "BST.h"
//tek tek alýnmadýgýnda problem var.Benzer isimde nesneler yuzunden.
//#include "heap.h"
//#include "trie.h"


time_t start,end;
double dif;
int main()
{
	ifstream infile("AOL.txt");
	
	time (&start);
	cleartext(infile);
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for clearing data", dif);;cout<<endl;
	
	
	//------------------------------------------------------ BST
	time (&start);
	ifstream file("AOL1K.txt");
 	binarySort(file);
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for 1k", dif);cout<<endl;
	
	time (&start);
	ifstream file2("AOL100K.txt");
 	binarySort(file2);
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for 100k", dif);cout<<endl;
	
	time (&start);
	ifstream file3("AOL1M.txt");
 	binarySort(file3);
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for 1M", dif);cout<<endl;
	
	time (&start);
	ifstream file4("AOL3M.txt");
 	binarySort(file4);
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for 3M", dif);cout<<endl; 
	
	//-------------------------------------------------------- HEAP  SORT
	
/*	
	time (&start);
	ifstream text1("AOL1K.txt");
	ofstream out1("heap_1k.txt");
	heapsort(text1,out1);
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for 1k", dif);cout<<endl;
	
	time (&start);
	ifstream text2("AOL100K.txt");
	ofstream out2("heap_100k.txt");
	heapsort(text2,out2);
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for 100k", dif);cout<<endl;
	
	time (&start);
	ifstream text3("AOL1M.txt");
	ofstream out3("heap_1M.txt");
	heapsort(text3,out3);
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for 1M", dif);cout<<endl;
		
	//time (&start);
	//ifstream file("AOL3M.txt");
	//over1mHEAP(file);
	//time (&end);
	//dif = difftime (end,start);
	//printf("Elasped time is %.2lf seconds for 3M", dif);cout<<endl;

*/
	
	//--------------------------------------------------------- TRIE
/*
	string token,temp;
	
	time (&start);
	Trie* trie = new Trie();
	ifstream text("AOL1K.txt");
	while (getline(text,token)){
		trie->addWord(token);}
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for 1K", dif);cout<<endl;
	delete trie;
	
	time (&start);
	Trie* trie2 = new Trie();	
	ifstream text2("AOL100k.txt");
	while (getline(text2,token)){
		trie2->addWord(token);}
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for 100k", dif);cout<<endl;
	delete trie2;
	
	time (&start);
	Trie* trie3 = new Trie();	
	ifstream text3("AOL1M.txt");
	while (getline(text3,token)){
		trie3->addWord(token);}
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for 1M", dif);cout<<endl;
	delete trie3;
	
   	time (&start);
   	Trie* trie4 = new Trie();	
	ifstream text4("AOL3M.txt");
	while (getline(text4,token)){
		trie4->addWord(token);}
	time (&end);
	dif = difftime (end,start);
	printf("Elasped time is %.2lf seconds for 3M", dif);cout<<endl;
	delete trie4;

*/	
	return 0;
}


