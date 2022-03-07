#include "labo.h"
#include <string.h>

void ajouter(Node* head, void* item)
{
	Node* n = allocate(sizeof(Node));
	n->data = item;
	n->next = NULL;
	n->prev = head->prev;
	head->prev = n;
	if (n->prev->next != NULL) 
	{
		n->prev->next = n;
	}
}

void enlever(Node* head, void* name)
{
	Node* last = allocate(sizeof(Node));
	Item* item = name;
	while (head != NULL)
	{
		if (head->data == item->nom)
		{
			if (head->prev != NULL) 
			{
				last = head->prev;
				head->prev = last->prev;
				if (last->prev != NULL)
				{
					last->prev->next = NULL;
				}
			}
		}
	}
}

Node* trouverItemPos(Node* head, void* pos)
{
	
}

int trouverItemNom(Node* head, char* name)
{
	
	Node* n = head;
	Item* item;
	int count = 0;
	while (n != NULL)
	{
		Item* item = n->data;
		if (item->nom == name)
		{
			return count;
		}
		count++;
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
