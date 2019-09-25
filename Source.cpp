#pragma once
#include <string>
#include <iostream>

using namespace std;

class doublyLL
{
private:
	class node
	{
	public:
		string data;
		node * next;
		node * prev;

		node(string x)
		{
			data = x;
			next = nullptr;
			prev = nullptr;
		}
	};

	node * head;
	node * tail;

public:
	doublyLL()
	{
		head = nullptr;
		tail = nullptr;
	}

	//Add item x to back of list
	//Won't work for empty case (walk through code with a picture to see why).
	//Try to make it work for the empty case.
	void addBack(string x)
	{
		node * baby = new node(x);
		if (head == nullptr)
		{
			head = baby;
			tail = baby;
		}
		//General case where there are lots of nodes:  Does it work for the empty case? (No)
		else
		{
			baby->prev = tail;
			tail->next = baby;
			tail = baby;
		}
	}

	//Write a display method to see if your addBack method works.
	void display()
	{
		node*temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
			
		}
		delete temp;
		cout << endl;
	}

	//Write a displayBackwards method to use the tail pointer and prev pointers.
	void backWard()
	{
		node*temp = tail;
		while (temp != nullptr)
		{
			cout << temp->data << " -> ";
			temp = temp->prev;
			
		}
		delete temp;
		cout << endl;
	}
	void addFront(string x)
	{
		node*babyNode = new node(x);
		if (head == nullptr)
		{
			head = babyNode;
			tail = babyNode;
		}
		else
		{
			babyNode->next = head;
			head->prev = babyNode;
			head = babyNode;
		}
	}
	void remove(string x)
	{
		node*temphead = head;
		node*temptail = tail;
		if (head==nullptr&&tail==nullptr)
		{
			cout << "Empty list" << endl;
		}
		else if (head->data == x && tail->data == x)
		{
			head = nullptr;
			tail = nullptr;
			cout << "You remove everything!" << endl;
		}
		else if (temphead->data == x)
		{
			head = temphead->next;
			head->prev = nullptr;
			delete temphead;
		}
		else if (temptail->data == x)
		{
			tail = temptail->prev;
			tail->next = nullptr;
			delete temptail;
		}
		else
		{
			while (temphead->next != nullptr && temphead->next->data != x)
			{
				temphead = temphead->next;
			}
			temphead->next = temphead->next->next;
			temphead->next->next->prev = temphead;
			delete temphead->next;
		}
	}
	void removeThird()
	{
		node*temp = head;
		int count = 1;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			count++;
			if (count == 3)
			{
				node*remove = temp;
				temp = temp->next;
				remove->prev->next = temp;
				temp->prev = remove->prev;
				delete remove;
				count = 1;
			}
		}
	}
};
int main()
{
	doublyLL listA;
	
	listA.addBack("Girl");
	listA.addBack("Hey");
	listA.addBack("Yo");
	listA.addFront("PokeMon");
	

	
	listA.backWard();
	listA.remove("PokeMon");
	listA.remove("Girl");
	listA.remove("Yo");
	listA.remove("Hey");
	listA.display();
	listA.addFront("Ang");
	listA.addFront("Gimmo");
	listA.addBack("Tti?");
	listA.addFront("¾È³ç");
	listA.addBack("H?");
	listA.addBack("O?");
	listA.addBack("G?");
	listA.addBack("U?");

	listA.display();
	listA.removeThird();
	listA.display();

	return 0;
}