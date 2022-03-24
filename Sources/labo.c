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
	n->prev = head;
}

void enlever(Node* head, char* name)
{
	Node* n = head->next;
	while (n != NULL)
	{
		Item* item = n->data;
		if (item->nom == name)
		{
			if (n->next != NULL)
			{
				n->prev->next = n->next;
				n->next->prev = n->prev;
			}
			else
			{
				n->prev->next = n->next;
			}
			break;
		}
		n = n->next;
	}
}

Item* trouverItemPos(Node* head, void* pos)
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

Item* trouverItemNom(Node* head, char* name)
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
	// apres m'avoir essayer de faire quelque chose de moi-meme, je me suis resolu a chercher des solutions sur internet :
	// https://stackoverflow.com/questions/35914574/sorting-linked-list-simplest-way
	// je sais comment il marche, je m'en allait un peu sur cette lancer la, sauf que certaine parti ne fonctionnais pas
	// j'ai donc mit en commentaire les etapes pour demontrer que je comprend comment il marche
	Node* n = head->next;
	//on regarde s'il n'est pas NULL
	while (n != NULL)
	{
		//On utilise une variable temporaire pour passer a travers tout les donnees de la liste chainee
		Node* tempNode = n;
		while (tempNode->next != NULL)
		{
			Item* item = tempNode->data;
			Item* item2 = tempNode->next->data;
			//s'il est plus grand ils vont s'echanger
			if (item->cost > item2->cost)
			{
				//bon j'ai essayer de faire une fonction swap avec mais sa a pas l'air de fonctionner autre qu'avec ca
				//je pense que c'est a cause qu'il n'echangeaient pas, meme si je mettais &data1
				void* temp = tempNode->data;
				tempNode->data = tempNode->next->data;
				tempNode->next->data = temp;
			}
			//on prend l'autre d'apres pour continuer la boucle
			tempNode = tempNode->next;
		}
		//on refait la meme chose pour l'autre, ce qui fait que sa va finir la boucle
		n = n->next;
	}
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

void ajouterFromFile(Node* head)
{
	Node* n = head->next;

	FILE* data = fopen("data.csv", "r");
	// fonction pour ajouter dans le head les objets qui sont dans le data.csv
	
}
