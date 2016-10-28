#include "StdAfx.h"
#include "AlgorithmTest.h"

#include <time.h>
#include <stdlib.h>
#include <iostream>

const int g_array_len = 10;
static int g_array[g_array_len] = {23,43,21,41,16,67,2,45,24,33};

#define NEWLINE (std::cout<<std::endl);	

AlgorithmTest::AlgorithmTest(void)
{
	srand((int)time(0));
}

AlgorithmTest::~AlgorithmTest(void)
{
}

void AlgorithmTest::InsertDataToList(ListNode*& head, int data)
{
	if(NULL == head)
	{
		head = new ListNode;
		head->data = data;
		return;
	}

	ListNode* cur = head;
	while (NULL != cur)
	{
		if(cur->next == NULL)
		{
			ListNode* add = new ListNode;
			add->data = data;	
			cur->next = add;
			break;
		}

		cur = cur->next;

	}
}

void AlgorithmTest::InsertArrayToList(ListNode*& head, int a[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		InsertDataToList(head, a[i]);
	}
}

void AlgorithmTest::DisplayList(ListNode* head)
{
	ListNode* cur= head;
	while(cur != NULL)
	{
		std::cout<<cur->data<<" ";
		cur = cur->next;
	}

	std::cout<<std::endl;
}

void AlgorithmTest::ListBubbleSort(ListNode*& head)
{
	ListNode* first = new ListNode;
	first->next = head;

	ListNode* pre = first;
	ListNode* cur = head;
	ListNode* end = NULL;

	while (end != head)
	{
		while (cur->next != end)
		{
			if (cur->data > cur->next->data)
			{
				//swap
				pre->next = pre->next->next;
				cur->next = pre->next->next;
				pre->next->next = cur;

			}
			else
			{
				cur = cur->next;
			}

			pre = pre->next;
			
		}
		
		end = cur;
		pre = first;
		cur = pre->next;

	}

	head = first->next;
	delete first;
}

void AlgorithmTest::ListReverse(ListNode*& head)
{
	ListNode* pre = NULL;
	ListNode* cur = head;
	ListNode* temp = NULL;


	while (cur->next != NULL)
	{
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	
	cur->next = pre;
	head = cur;
}


void AlgorithmTest::TestList()
{
	std::cout<<"test list"<<std::endl;
	ListNode* list = NULL;
	InsertArrayToList(list, g_array, sizeof(g_array)/sizeof(int));
	
	std::cout<<"source list is"<<std::endl;
	DisplayList(list);

	std::cout<<"test list bubble Sort"<<std::endl;
	ListBubbleSort(list);
	DisplayList(list);

	std::cout<<"test list reverse"<<std::endl;
	ListReverse(list);
	DisplayList(list);
}

void AlgorithmTest::BubbleSort(int a[], int len)
{
	for(int i =  0; i < len - 1; ++i)	
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void AlgorithmTest::QuickSort(int a[], int low, int high)
{

	if (low >= high)
	{
		return;
	}

	int t_low = low;
	int t_high = high;
	int key = a[low];

	while (t_low < t_high)
	{
		while (t_low < t_high && a[t_high] >= key)
		{
			--t_high;
		}
		
		a[t_low] = a[t_high];

		while (t_low < t_high && a[t_low] <= key)
		{
			++t_low;
		}

		a[t_high] = a[t_low];
	}
	
	a[t_low] = key;
	
	QuickSort(a, low, t_low-1);
	QuickSort(a, t_high+1, high);
}

void AlgorithmTest::TestSort()
{	
	std::cout<<"source data is: "<<std::endl;
	GetRamdonData(g_array, g_array_len);
	DisplayArray(g_array, g_array_len);

	std::cout<<"test Bubble Sort"<<std::endl;
	BubbleSort(g_array, g_array_len);
	DisplayArray(g_array, g_array_len);

	std::cout<<"source data is: "<<std::endl;
	GetRamdonData(g_array, g_array_len);
	DisplayArray(g_array, g_array_len);

	
	std::cout<<"test Quick Sort"<<std::endl;
	QuickSort(g_array, 0, g_array_len-1);
	DisplayArray(g_array, g_array_len);

}

void AlgorithmTest::DisplayArray(int a[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout<<a[i]<<" ";
	}

	std::cout<<std::endl;
}

void AlgorithmTest::GetRamdonData(int a[], int len)
{

//generate random number no more than X
#define random(x) (rand()%x)
	for(int i = 0;i < len; i++)
		a[i] = random(100);
}

void AlgorithmTest::AutoTest()
{
	TestList();
	NEWLINE;
	TestSort();
	NEWLINE;
	TestBTree();
	NEWLINE;
	
}

void AlgorithmTest::InsertArrayToBSTree(BSTree& tree, int a[], int len)
{

	for (int i = 0; i < len; ++i)
	{
		//use way of inserting data
		//InsertDataToBSTree(tree.root, a[i]);
		
		//use way of inserting node
		BTreeNode* add = new BTreeNode(a[i]);
		InsertNodeToBSTree(tree.root, add);
	}
}	

void AlgorithmTest::InsertNodeToBSTree(BTreeNode*& root, BTreeNode* add)
{
	int data = add->data;

	if(NULL == root)
	{
		root = add;
	}
	else
	{
		BTreeNode* temp = NULL;

		if (data >= root->data)
		{
			if (NULL == root->right)
			{
				root->right = add;
			}
			else
			{
				InsertNodeToBSTree(root->right, add);
			}

		}
		else
		{
			if (NULL == root->left)
			{
				root->left = add;
			} 
			else
			{
				InsertNodeToBSTree(root->left, add);
			}

		}

	}
}

void AlgorithmTest::InsertDataToBSTree(BTreeNode*& root, int data)
{
	
	
	if(NULL == root)
	{
		BTreeNode* add = new BTreeNode;
		add->data = data;
		root = add;
	}
	else
	{
		BTreeNode* temp = NULL;

		if (data >= root->data)
		{
			if (NULL == root->right)
			{
				BTreeNode* add = new BTreeNode;
				add->data = data;
				root->right = add;
			}
			else
			{
				InsertDataToBSTree(root->right, data);
			}

		}
		else
		{
			if (NULL == root->left)
			{
				BTreeNode* add = new BTreeNode;
				add->data = data;
				root->left = add;
			} 
			else
			{
				InsertDataToBSTree(root->left, data);
			}
			
		}

	}
		
}

void AlgorithmTest::DeleteDataFromTree(BTreeNode*& root, int data)
{
	if (data == root->data)
	{
		if (NULL == root->left && NULL == root->right)			//have no child
		{
			root = NULL;
		}
		else if (NULL != root->left && NULL != root->right)		//have two child
		{
			InsertNodeToBSTree(root->right,root->left);
			root = root ->right;
		}
		else													//have one child
		{
			root = root->right != NULL? root->right:root->left;
		}

	}
	else if (data >= root->data)
	{
		DeleteDataFromTree(root->right, data);
	}
	else if (data < root->data)
	{
		DeleteDataFromTree(root->left, data);
	}

}

void AlgorithmTest::MidOrderTraverse(BTreeNode* root)
{
		if(NULL == root) return;
		MidOrderTraverse(root->left);
		std::cout<<root->data<<" ";
		MidOrderTraverse(root->right);
}

void AlgorithmTest::TestBTree()
{
	BSTree tree;
	
	std::cout<<"source data is: "<<std::endl;
	GetRamdonData(g_array, g_array_len);
	DisplayArray(g_array, g_array_len);

	std::cout<<"test insert array to BST and Order Traversal"<<std::endl;
	InsertArrayToBSTree(tree, g_array, g_array_len);
	MidOrderTraverse(tree.root);
	
	NEWLINE;
	std::cout<<"test delete "<<g_array[0]<<" and "<<g_array[1]<<std::endl;
	DeleteDataFromTree(tree.root, g_array[0]);
	DeleteDataFromTree(tree.root, g_array[1]);
	MidOrderTraverse(tree.root);

}

