#include <iostream>
#include <string>
#include <fstream>

using namespace std;
	
struct xNode {
	string number;
	int h;// height
	xNode* right;
	xNode* left;
};
typedef xNode* Nodeptr;

int hight(Nodeptr xNode){
	if (xNode==NULL)
		return -1;
	else
		return xNode->h;
}
int maxhight(int a,int b){
	if (a<b){
		return b;}
	else{
		return a;} 
}
Nodeptr slr(Nodeptr root){//single left rotation	
	Nodeptr temp=NULL;
	temp = root->right;
   	root->right = temp->left;
   	temp->left = root;
	root->h = maxhight(hight(root->left),hight(root->right))+1;
    	temp->h = maxhight(hight(temp->right),root->h)+1;	
	return temp;
}
Nodeptr srr(Nodeptr root){//single right rotation	
	Nodeptr temp=NULL;
	temp = root->left;
    	root->left = temp->right;
    	temp->right = root;
	root->h = maxhight( hight( root->left ), hight( root->right ) ) + 1;
        temp->h = maxhight( hight( temp->left ), root->h ) + 1;
	return temp;
}
Nodeptr dlr(Nodeptr root)//double left rotation
{
	root->right = srr(root->right);
	return slr(root);
}
Nodeptr drr(Nodeptr root)//double right rotation
{
	root->left = slr(root->left);
	return srr(root);
}
Nodeptr insert(Nodeptr& root,string number){	
	if (root==NULL){
		root=new xNode;
		root->number=number;
		root->h=0;
		root->right=NULL;
		root->left=NULL;
	}
	else if(number > root->number){
		insert(root->right,number);
		if (hight(root->right)-hight(root->left)==2)
			if(number > root->right->number)
				root = slr(root);	// single left	rotation
			else//double left rotation	
				root = dlr(root);						
	}
	else if(number < root->number){
		insert(root->left,number);
		if (hight(root->left)-hight(root->right)==2)
			if(number < root->left->number)
				root = srr(root);	// sing right rotation	
			else//double right rotation	
				root = drr(root);
	}
	root->h = maxhight( hight( root->left ), hight( root->right ) ) + 1;	
	return root;	
}

void mlr(Nodeptr t,ofstream &out)
{
    if (t == NULL)
        return;
    mlr(t->left,out);
    out << t->number <<endl;
    mlr(t->right,out);
}
void binarySort(ifstream & infile)
{
	Nodeptr tree = NULL;
 	string tmp;
 	ofstream end("BST_result.txt");
    while(getline(infile,tmp)){ 
        insert(tree,tmp);}
	mlr(tree,end);
}

