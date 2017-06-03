#include <iostream>    
#include <string>
#include <fstream>
#include "merge.h"
using namespace std;

struct heap
{
	int size;
	string arr[1000001];
};
typedef heap* MinHeapPtr;
void swap (int first , int second , string arr[]){
	string temp;
	temp = arr[first];
	arr[first]= arr[second];
	arr[second]=temp;}
int min(int first ,int second, string arr[]){
	if (arr[first] <= arr[second])
		return first;
	else
		return second;}
void downHeap(int index, MinHeapPtr& myHeap)
{    		
    int length = myHeap->size-1;        
    int leftChildIndex = 2*index;
    int rightChildIndex = 2*index+1; 
 	if(leftChildIndex >= length+1)
        return; 
    else
    {
	string left  = myHeap->arr[leftChildIndex];
        string right = myHeap->arr[rightChildIndex];
        int minIndex = index;      
        if (myHeap->arr[index] > left || myHeap->arr[index] > right)
        {      
  	    minIndex = leftChildIndex;
	    if(rightChildIndex < length+1)
            {
                if (left > right)
                {
      	            minIndex = rightChildIndex;
                }}           
            swap(index,minIndex,myHeap->arr);
            downHeap(minIndex, myHeap);
        }
    }
}
void upHeap(int index,MinHeapPtr& myHeap)
{	
	while (1 <= index){
		if (myHeap->arr[index] < myHeap->arr[index/2]){			
			swap(index,index/2,myHeap->arr);	
			index=index/2;
		}
		else
			break;			
	}	
}
string getMin(MinHeapPtr myHeap)
{
	return myHeap->arr[1];
}
void extractMin(MinHeapPtr& myHeap)
{
	if(myHeap->size == 0)
        	return;
    	else{	
		myHeap->arr[1]= myHeap->arr[myHeap->size -1];
		myHeap->size = myHeap->size - 1 ;
		downHeap(1,myHeap);}
}
bool isEmpty(MinHeapPtr& myHeap)
{
	if(myHeap->size==1)
	{
		return true;
	}else{
		return false;
	}
}
void insert(string newValue, MinHeapPtr& myHeap)
{   
    myHeap->size++;
    myHeap->arr[myHeap->size-1]=newValue;    
    upHeap(myHeap->size-1, myHeap);
}
void heapsort(ifstream & infile ,ofstream &output )
{
	MinHeapPtr X = new heap;	
	X->size = 1;
	string token,temp;
	while (getline(infile,token))
		insert(token,X);
	temp =getMin(X);
	extractMin(X);	   	
	while(!isEmpty(X))
    	{
		token =getMin(X);
		if (temp!=token)
			output << temp <<endl;
		temp=token;
		extractMin(X);	
    	}
    output << temp;
}
/*void over1mHEAP(ifstream &bigdata)
{
	divide (bigdata);
	ifstream out1("out1.txt");
	ifstream out2("out2.txt");
	ifstream out3("out3.txt");
	ifstream out4("out4.txt");
	ofstream out1s("out1_sorted.txt");
	ofstream out2s("out2_sorted.txt");
	ofstream out3s("out3_sorted.txt");
	ofstream out4s("out4_sorted.txt");
	ofstream main1("main1_sorted.txt");
	ofstream main2("main2_sorted.txt");
	ofstream result("Heap_Sort_Big_Data.txt");
	out1s.open("out1_sorted.txt");
	out2s.open("out2_sorted.txt");
	out3s.open("out3_sorted.txt");
	out4s.open("out4_sorted.txt");
	main1.open("main1_sorted.txt");
	main1.open("main2_sorted.txt");
	heapsort(out1,out1s);
	heapsort(out2,out2s);
	heapsort(out3,out3s);
	heapsort(out4,out4s);
	out1s.close("out1_sorted.txt");
	out2s.close("out2_sorted.txt");
	out3s.close("out3_sorted.txt");
	out4s.close("out4_sorted.txt");
	ifstream merge1("out1_sorted.txt");
	ifstream merge2("out2_sorted.txt");
	ifstream merge3("out3_sorted.txt");
	ifstream merge4("out4_sorted.txt");
	merge(merge1 , merge2 ,main1);
	merge(merge3 , merge4 ,main2);
	main1.close("main1_sorted.txt");
	main1.close("main2_sorted.txt");
	ifstream last1("main1_sorted.txt");
	ifstream last2("main2_sorted.txt");
	merge(last1,last2,result);
	remove("out1.txt");
	remove("out2.txt");
	remove("out3.txt");
	remove("out4.txt");
	remove("out1_sorted.txt");
	remove("out2_sorted.txt");
	remove("out3_sorted.txt");
	remove("out4_sorted.txt");
	remove("main1_sorted.txt");
	remove("main2_sorted.txt");
}*/

