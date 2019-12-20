#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
	struct node* random;
};
node* start = NULL;
node* duplicate = NULL;

void addAtBegining (int data){
	node * n = new node ();
	n->data = data;
	n->next = start;
	start = n;
}

void printList (node* start){
    cout << endl;
	node *t = start;
	while (t != NULL){
		cout << t->data << "\t";
		t = t->next;
	}
	cout << endl;
}

void printRandom (node* start){
	node* t = start;
	while (t != NULL){
		if (t->random != NULL)
			cout << t->random->data << "\t";
		else
			cout << "null" << "\t";
		t = t->next;
	}
}

void setRandom (int s, int d){
	node* t = start;
	node* ts;
	node* td;
	
	while (t != NULL){
		if (t->data == s)
			ts = t;
		else if (t->data == d)
			td = t;
	    t = t->next;
	}
	
	ts->random = td;
}

void createNode (node** ref, node* ts){
    *ref = new node ();
    node* c = *ref;
	c->data = ts->data;
	c->next = ts->next;
	c->random = ts->random;
}

node** copyList (){
	node* ts = start;
	node* c = NULL;
	node* temp = NULL;
	while (ts != NULL){
		temp = ts->next;
		createNode (&c, ts);
		ts->next = c;
		ts = temp;
	}
	printList (start);
	
	ts = start;
	while (ts != NULL){
		ts->next->random = ts->random->next;
		ts = ts->next->next;
	}
	
    ts = start;
	duplicate = start->next;
	c = NULL;
	while (ts != NULL){
		temp = ts->next->next;
		if (c == NULL){
			c = ts->next;
		}
		else{
			c->next = ts->next;
			c = c->next;
		}
		ts->next = temp;
		ts = ts->next;
	}
	return &duplicate;
}

int main (){

	addAtBegining (4);
	addAtBegining (3);
	addAtBegining (2);
	addAtBegining (1);
	printList (start);
	
	setRandom (1, 3);
	setRandom (4, 2);
	setRandom (3, 1);
	setRandom (2, 1);
	printRandom (start);
	
	node** d = copyList ();
	cout << "Original:" << endl;
	printList (start);
	printRandom (start);
	cout << "\nDuplicate:" << endl;
	
	printList (*d);
	printRandom (*d);
	return 0;
}