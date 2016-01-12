#include<iostream>
#include<vector>
#define T int
//无逆序子序列归并排序
using namespace std;

struct Node
{
	Node* next;
	T value;
	Node(T val)
	{
		value = val;
		next = NULL;
	}
};

Node* MakeLink(T* dat, int n)
{
	Node* head = new Node(0);
	Node* p = head;
	for (int i = 0; i < n; i++)
	{
		p->next = new Node(dat[i]);
		p = p->next;
	}
	return head;
}
void Group(Node* head, vector<Node*>& G)
{
	Node* p = head->next;
	G.push_back(head);
	while (p->next != NULL)
	{
		if (p->value > p->next->value)
		{
			Node *h = new Node(0);
			G.push_back(h);
			h->next = p->next;
			p->next = NULL;
			p = h->next;
		}
		else
		{
			p = p->next;
		}
	}
}

Node* MergeLink(Node* a, Node* b)
{
	Node* pa = a->next;
	Node* pb = b->next;
	if (pa == NULL) return b;
	if (pb == NULL) return a;
	Node* head = new Node(0);
	Node* p = head;
	while (pa != NULL&&pb != NULL)
	{
		if (pa->value < pb->value) {
			p->next = pa;
			pa = pa->next;
		}
		else
		{
			p->next = pb;
			pb = pb->next;
		}
		p = p->next;
	}
	p->next = NULL;
	while (pa != NULL)
	{
		p->next = pa;
		pa = pa->next;
		p = p->next;
	}
	while (pb != NULL)
	{
		p->next = pb;
		pb = pb->next;
		p = p->next;
	}
	return head;
}

void MergeSort(T* dat, int n)
{
	Node* head = MakeLink(dat, n);
	vector<Node*> G;
	Group(head, G);
	int gn = G.size();
	for (int step = 1; step < gn; step *= 2)
	{
		int i = 0;
		for (i = 0; i + step < gn; i += 2 * step)
		{
			Node* a = G[i];
			Node* b = G[i + step];
			G[i] = MergeLink(a, b);
		}
	}

}
void main()
{
	T dat[] = { 9,2,65,3,5,2,8,6,10,4 };
	MergeSort(dat, 10);
	for (int i = 0; i < 10; i++)
		std::cout << dat[i] << std::endl;

}