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
	Node* n = head->next;
	while (n->next != NULL)
	{
		Node* nextNode = n->next;
		Item* item = n->data;
		Item* item2 = nextNode->data;
		if (item2->cost > item->cost)
		{
			swap(n->data, nextNode->data);
		}
		if (n->next == NULL)
		{
			break;
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
		n = n->next;
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

void ajouterRandom(Node* inventaire, Node* head)
{
	Node* n = head->next;
	Node* joueur = inventaire->next;
	// fiole = 1, sword = 2, chainmail = 3, boots = 4
	int nombreRandom = rand() % 4 + 1;
	int count = 0;
	switch (nombreRandom)
	{
	case 1:
		ajouter(joueur, n->data);
		break;
	case 2:
		while (n != NULL)
		{
			if (count == 1)
			{
				ajouter(joueur, n->data);
				break;
			}
			n = n->next;
			count++;
		}
		break;
	case 3:
		while (n != NULL)
		{
			if (count == 2)
			{
				ajouter(joueur, n->data);
				break;
			}
			n = n->next;
			count++;
		}
		break;
	case 4:
		while (n != NULL)
		{
			if (count == 3)
			{
				ajouter(joueur, n->data);
				break;
			}
			n = n->next;
			count++;
		}
		break;
	}
}

void lireFichier();

void ajouterFromFile();
