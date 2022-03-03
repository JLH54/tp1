#include "labo.h"
#include <string.h>

void ajouter(Node* head, void* item)
{
	Node* n = allocate(sizeof(Node));
	n->data = item;
	head->next = n;
	n->next = NULL;
}

void enlever(Node* head, void* nom)
{

}

Node* trouverItemPos(Node* head, void* pos)
{
	
}

Node* trouverItemNom(Node* head, char* name)
{
	
	Node* n = head;
	Node* previousNode;
	while (n != NULL)
	{
		if (p->name == name)
		{
			memset(n, 0, sizeof(Node));
			return previousNode;
		}
		previousNode = n;
		n = n->next;
	}
}


void trier(Node* head)
{
	
}

void swap(Node* a, Node* b)
{
	
}

int qteItems(Node* head)
{

}

// a ne pas faire tout de suite
void ajouterRandom(Node head);

void lireFichier();

void ajouterFromFile();
