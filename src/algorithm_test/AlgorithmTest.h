#pragma once

struct ListNode
{
	ListNode():
		next(NULL),data(0)
	{

	}

	ListNode* next;
	int data;
};

struct BTreeNode
{
	BTreeNode():
		left(NULL),right(NULL),data(0)
	{
	}

	BTreeNode(int d):
	left(NULL),right(NULL),data(d)
	{
	}

	BTreeNode* left;
	BTreeNode* right;
	int data;
};

struct BSTree
{
	BSTree():
		root(NULL), size(0)
	{

	}

	BTreeNode* root;
	int size;
};


class AlgorithmTest
{
public:
	AlgorithmTest(void);
	~AlgorithmTest(void);

	void DisplayArray(int a[], int len);
	void GetRamdonData(int a[], int len);

	//Algorithm for List
	void InsertDataToList(ListNode*& head, int data);				//head pointer may be changed ,so use ref
	void InsertArrayToList(ListNode*& head, int a[], int len);
	void ListBubbleSort(ListNode*& head);
	void ListReverse(ListNode*& head);

	void DisplayList(ListNode* head);
	void TestList();

	//test Sort
	void BubbleSort(int a[], int len);
	void QuickSort(int a[], int low, int high);
	void TestSort();

	//Algorithm for Binary Tree
	void InsertArrayToBSTree(BSTree& head, int a[], int len);
	void InsertDataToBSTree(BTreeNode*& root, int data);
	void InsertNodeToBSTree(BTreeNode*& root, BTreeNode* add);
	void DeleteDataFromTree(BTreeNode*& root, int data);
	void MidOrderTraverse(BTreeNode* root);
	void TestBTree();

	//auto test all algorithm
	void AutoTest();
	
};
