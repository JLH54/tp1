#include "labo.h"
#include <stdio.h>
#include <string.h>

void ajouter(Node* head, void* item)
{
	Node* n = allocate(sizeof(Node));
	n->data = item;
	if (head->next == NULL)
	{
		n->next = NULL;
	}
	else
	{
		n->next = head->next;
	}
	head->next = n;
	n->prev = head->prev;
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
	// il faut retourner la struct donc ce serait le item
	Node* n = head;
	Item* item;
	int count = 0;
	while (n != NULL)
	{
		Item* item = n->data;
		if (count == pos)
		{
			return item;
		}
		count++;
	}
}

int trouverItemNom(Node* head, char* name)
{
	// il faut retourner la struct donc ce serait le item
	Node* n = head;
	Item* item;
	int count = 0;
	while (n != NULL)
	{
		Item* item = n->data;
		if (item->nom == name)
		{
			return item;
		}
		count++;
	}
}


void trier(Node* head)
{
	// Trier la liste d'items dans l'inventaire relatif à leur valeur de vente
	Item* item;
	Item* item2;
	Node* n = head->next;
	while (n != NULL)
	{
		Node* nextNode = n->next;
		item = n->data;
		item = nextNode->data;
		if (item2->cost > item->cost)
		{
			swap(n->data, nextNode->data);
		}
		n = n->next;
	}
}

void swap(void* data1, void* data2)
{
	void* temp;
	temp = data1;
	data1 = data2;
	data2 = temp;
}

int qteItems(Node* head)
{
	Node* n = head;
	int count = 0;
	while (n != NULL)
	{
		count++;
	}
	return count;
}


void montrerCeQuiA(Node* head)
{
	Node* n = head->next;
	while (n != NULL)
	{
		Item* item;
		item = n->data;
		printf("Le nom : %s\n", item->nom);
		printf("Son cout : %d\n", item->cost);
		n = n->next;
	}
}

// a ne pas faire tout de suite
void ajouterRandom(Node head)
{
	// fiole = 1, sword = 2, chainmail = 3, boots = 4

}

void lireFichier();

void ajouterFromFile();
