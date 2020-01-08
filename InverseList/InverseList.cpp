// InverseList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node
{
public:
	int val;
	Node* next;

	Node(int val1)
	{
		val = val1;
	}
};

class List
{
public:
	Node* startNode;
	Node* currentNode;
	List()
	{
		startNode = NULL;
		currentNode = NULL;
	}
	void push_back(int value)
	{
		Node *n = new Node(value);
		n->next = NULL;
		if (startNode == NULL)
		{
			startNode = n;
			currentNode = n;
			currentNode->next = NULL;
		}
		else
		{
			currentNode->next = n;
			currentNode = n;
		}
	}

	void Reverse()
	{
		Node* curNode = startNode;
		Node* tempNode = startNode->next;
		curNode->next = NULL;
		while (tempNode != NULL)
		{
			Node* tempNode1 = tempNode->next; // Save next node of temp node

			tempNode->next = curNode; // Assign tempNode to current node
			curNode = tempNode; // Shift curNode by one position
			tempNode = tempNode1; // Shift tempNode by one position
		}
		startNode = curNode;
	}

	void PrintList()
	{
		/*Node* curNode= startNode;
		while (curNode->next != NULL)
		{
			cout << curNode->val << endl;
			curNode = curNode->next;
		}*/
		cout << startNode->val << startNode->next->val << startNode->next->next->val << startNode->next->next->next->val << endl;
	}
};
int main()
{
	List lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	lst.Reverse();
	lst.PrintList();
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
