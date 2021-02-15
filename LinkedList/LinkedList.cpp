#include <iostream>

using namespace std;

struct List
{
	int data;
	List *next = nullptr;
};

void add_node(List *a)
{
	List* newNode = new List;
	a->next = newNode;
	cin >> a->next->data;
}

void print_list (List *curNode)
{
	while (curNode->next != nullptr)
	{
		cout << curNode->data << endl;
		curNode = curNode->next;
	}
	cout << curNode->data << endl;
}

void create_list(List *curNode, int n)
{
	List* curTail = curNode;
	for (int i = 0; i < n - 1; i++)
	{
		add_node(curTail);
		curTail = curTail->next;
	}
}

void sort_list(List *curNode, int n)
{
	List *tempNode = curNode;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n-i; j++)
		{
			while (curNode != nullptr)
			{
				if (curNode->next == nullptr)
					break;
				if (curNode->next->data > curNode->data)
				{
					int temp = curNode->data;
					curNode->data = curNode->next->data;
					curNode->next->data = temp;
					curNode = curNode->next;
				}
				curNode = curNode->next;
			}
			curNode = tempNode;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "Введите количество элементов: ";
	int l;
	cin >> l;
	
	if (l <= 0)
		return 0;
	
	List *head = new List;
	cin >> head->data;
	
	create_list(head, l);
	cout << endl;
	
	print_list(head);
	cout << endl;
	
	sort_list(head, l);

	print_list(head);
}
