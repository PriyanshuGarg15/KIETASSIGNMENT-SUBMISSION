#include<iostream>
using namespace std;

struct node
{
	struct node *left, *right;
	int data;
};


node *join(node *lList, node *rList)	//Append rList at the end of the lList
{
	
	if (lList == NULL)				//CHecking for empty list
		return rList;
	if (rList == NULL)
		return lList;

	
	node *leftLast = lList->left;		// Saving the last node 	
	node *rightLast = rList->left;

	
	leftLast->right = rList;			// Connect the last node of Left List with the first node of the right List
			 
	rList->left = leftLast;
	lList->left = rightLast;
	rightLast->right = lList;

	return lList;
}


node *bList(node *root)
{
	if (root == NULL)
		return NULL;

	
	node *left = bList(root->left);
	node *right = bList(root->right);
	root->left = root->right = root;
	return join(join(left, root), right);
}


								// Create a new node and return its address
node *newnode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
								// Display Circular Link List
void displayCList(node *head)
{
	cout << "Dynamic List is :\n";
	node *itr = head;
	do
	{
		cout << itr->data <<" ";
		itr = itr->right;
	} while (head!=itr);
	cout << "\n";
}



// Sample Driver Program to use functions
int main()
{
int a,b,c,d,e,x;
cout<<"enter main root";
cin>>a;
cout<<"enter other nodes";
cin>>a>>b>>c>>d>>e;

	  node *root = newnode(10);
	
root->left = newnode(12);
	root->right = newnode(15);
	 root->left->left = newnode(25);
	 
root->left->right = newnode(30);
	root->right->left = newnode(36);

	node *head = bList(root);
	displayCList(head);

	return 0;
}
