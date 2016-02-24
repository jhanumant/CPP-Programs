#include <iostream>
using namespace std;

template <class T>
class LinkedList {
	private: 
		struct node {
			T data;
			struct node *next;
		} *root;
	public:
		LinkedList();
		void create();
		T middleElement();
		void print();
		void reverse();
};

template <class T> LinkedList<T>::LinkedList() {
	root = NULL;
}

template <class T> void LinkedList<T>::print() {
	node *temp = root;
	while (temp!=NULL) {
		cout << temp -> data;
		temp = temp -> next;
	}
}

template <class T> void LinkedList<T>::create() {
	node *temp;
	node *current = new node;
	char c = 'Y';
	do {
		temp = new node;
		cout << "Enter the node data:" <<endl;
		cin >> temp -> data;
		temp -> next = NULL;
		if (root == NULL) {
			root = temp;
		} else {
			current = root;
			while (current -> next != NULL) {
				current = current -> next;
			}
			current -> next = temp;
		}
		cout << "Do you want to continue?" <<endl;
		cin >> c;
	} while (c == 'Y');
	
}

template <class T> void LinkedList<T> :: reverse() {
	node *prev = NULL;
	node *current = root;
	node *nextNode ;
	while (current != NULL) {
		nextNode = current -> next;
		current -> next = prev;
		prev = current;
		current = nextNode;
	}
	root = prev;
	
}

template <class T> T LinkedList<T> :: middleElement() {
	node *slow = root;
	node *fast = root;
	while (fast&&fast->next!=NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow -> data;
}
int main() {
	LinkedList<int> list;
	list.create();
	list.print();
	list.reverse();
	list.print();
	int middle = list.middleElement();
	cout << "The middle Element is:" << middle;
	int a;
	cin >> a;
	return 0;
}