#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "labo.h"

uint8_t* heap = NULL;
size_t heap_top = 0;

/* This code is public domain -- Will Hartung 4/9/09 */
static size_t getline(char** lineptr, size_t* n, FILE* stream) {
	char* bufptr = NULL;
	char* p = bufptr;
	size_t size;
	int c;

	if (lineptr == NULL) {
		return -1;
	}
	if (stream == NULL) {
		return -1;
	}
	if (n == NULL) {
		return -1;
	}
	bufptr = *lineptr;
	size = *n;

	c = fgetc(stream);
	if (c == EOF) {
		return -1;
	}
	if (bufptr == NULL) {
		bufptr = malloc(128);
		if (bufptr == NULL) {
			return -1;
		}
		size = 128;
	}
	p = bufptr;
	while (c != EOF) {
		if ((p - bufptr) > (size - 1)) {
			size = size + 128;
			bufptr = realloc(bufptr, size);
			if (bufptr == NULL) {
				return -1;
			}
		}
		*p++ = c;
		if (c == '\n') {
			break;
		}
		c = fgetc(stream);
	}

	*p++ = '\0';
	*lineptr = bufptr;
	*n = size;

	return p - bufptr - 1;
}

// int test_code(FILE* f) {
// 	int out = 0;
// 	char* ligne = NULL;
// 	size_t len = 0;
// 	size_t read;
// 	int ligneCount = 0;

// 	size_t num_persons = 0;
// 	Node* n = NULL;
// 	int line = __LINE__;
// 	int hline = 0;
// 	while ((read = getline(&ligne, &len, f)) != -1) {
// 		char text[512] = { 0 };
// 		int i = 0;
// 		char chr = ligne[i];
// 		int isSearched = 0;
// 		Person p = persons[num_persons];
// 		while (i < read) {
// 			while (chr != ',' && chr != ' ' && chr != '\0') {
// 				text[strlen(text)] = chr;
// 				++i;
// 				chr = ligne[i];
// 			}
// 			if (strcmp(text, "name") == 0) {
// 				isSearched = 1;
// 				memset(text, 0, strlen(text));
// 			}
// 			else if (strcmp(text, "age") == 0) {
// 				isSearched = 1;
// 				memset(text, 0, strlen(text));
// 			}
// 			else if (isSearched && p.name[0] == '\0') {
// 				strcpy(p.name,text);
// 				memset(text, 0, strlen(text));
// 				isSearched = 0;
// 			}
// 			else if (isSearched && p.name[0] != '\0') {
// 				p.age =  atoi(text);
// 				memset(text, 0, strlen(text));
// 				isSearched = 0;
// 			}
// 			chr = ligne[++i];
// 		}
// 		persons[num_persons] = p;
// 		if (num_persons <= 1) {
// 			insertHead(&head, &persons[num_persons]); hline = __LINE__;
// 			n = head.next;
// 			if(num_persons == 1)
// 				assert(n != NULL);
// 		}
// 		else {
// 			insert(n, &persons[num_persons]); line = __LINE__;
// 			n = n->next;
// 		}
// 		num_persons++;
// 		ligneCount++;
// 	}
// 	//Validate insertion
// 	if (head.data == NULL) {
// 		fprintf(stderr, "Make sure the head Node gets set on insertHead, at line %i\n", hline);
// 		out = -1;
// 	}
// 	int i = 0;
// 	Node* node = &head;
// 	while (node != NULL) {
// 		Person* p = (Person*)node->data;
// 		if (p != NULL && (strcmp(p->name, persons[i].name) != 0 || p->age != persons[i].age)) {
// 			fprintf(stderr, "Insertion failed on person %s with age %i, at line %i\n", persons[i].name, (int)persons[i].age,line);
// 			out = -1;
// 		}
// 		node = node->next;
// 		++i;
// 	}
// 	Node* l = removeByData(&head, &persons[4]); line = __LINE__;
// 	Person* p = NULL;
// 	if(l != NULL)
// 		p = l->data;
// 	if (p == NULL || (strcmp(p->name, persons[3].name) != 0 && p->age != persons[3].age)) {
// 		fprintf(stderr, "Deletion by data failed on person %s with age %i, at line %i\n", persons[4].name, (int)persons[4].age, line);
// 		out =  -1;
// 	}
// 	if(l != NULL)
// 		insert(l, &persons[4]);
// 	l = removeByName(&head, persons[4].name); line = __LINE__;
// 	if (l != NULL)
// 		p = l->data;
// 	if (p == NULL || (strcmp(p->name, persons[3].name) != 0 && p->age != persons[3].age)) {
// 		fprintf(stderr, "Deletion by name failed on person %s with age %i, at line %i\n", persons[4].name, (int)persons[4].age, line);
// 		return -1;
// 	}
// 	if (l != NULL)
// 		insert(l, &persons[4]);
// 	sort(&head);
// }

// void verify_sort(FILE* f) {

// 	char* ligne = NULL;
// 	size_t len = 0;
// 	size_t read;
// 	int ligneCount = 0; 

// 	size_t num_persons = 0;
// 	Node* n = NULL;
// 	while ((read = getline(&ligne, &len, f)) != -1) {
// 		char text[512] = { 0 };
// 		int i = 0;
// 		char chr = ligne[i];
// 		int isSearched = 0;
// 		Person p = sorted_persons[num_persons];
// 		while (i < read) {
// 			while (chr != ',' && chr != ' ' && chr != '\0') {
// 				text[strlen(text)] = chr;
// 				++i;
// 				chr = ligne[i];
// 			}
// 			if (strcmp(text, "name") == 0) {
// 				isSearched = 1;
// 				memset(text, 0, strlen(text));
// 			}
// 			else if (strcmp(text, "age") == 0) {
// 				isSearched = 1;
// 				memset(text, 0, strlen(text));
// 			}
// 			else if (isSearched && p.name[0] == '\0') {
// 				strcpy(p.name, text);
// 				memset(text, 0, strlen(text));
// 				isSearched = 0;
// 			}
// 			else if (isSearched && p.name[0] != '\0') {
// 				p.age = atoi(text);
// 				memset(text, 0, strlen(text));
// 				isSearched = 0;
// 			}
// 			chr = ligne[++i];
// 		}
// 		sorted_persons[num_persons] = p;
// 		num_persons++;
// 		ligneCount++;
// 	}
// 	n = &head;
// 	int i = 0;
// 	int failed = 0;
// 	while (n != NULL) {
// 		Person* p = n->data;
// 		if (p->age != sorted_persons[i].age) {
// 			fprintf(stderr, "List wasn't sorted correctly.");
// 			failed = 1;
// 			break;
// 		}
// 		n = n->next;
// 		++i;
// 	}
// 	if (failed) {
// 		fprintf(stderr, "Expected order:\n");
// 		for (int y = 0; y < num_persons; ++y) {
// 			printf("name: %s, age: %i\n", sorted_persons[y].name, (int)sorted_persons[y].age);
// 		}
// 		fprintf(stderr, "Have order:\n");
// 		n = &head;
// 		while (n != NULL) {
// 			Person* p = n->data;
// 			printf("name: %s, age: %i\n", p->name, (int)p->age);
// 			n = n->next;
// 		}
// 	}
// }

int main(int argc, char** argv) {
	/*-Peupler la liste d'items
		- Ajouter l'item nomm� "fiole" dans l'inventaire
		- Peupler l'inventaire d'un nombre al�atoire d'items en consid�rant que la "fiole" a d�j� �t� ajout�.
		Choisir les autres items al�atoirement et les ajouter dans l'inventaire.
		- Imprimer dans la console les items dans l'inventaire
		- Trier la liste d'items dans l'inventaire relatif � leur valeur de vente
		- enlever l'item "fiole" en utilisant son nom.
		- Imprimer dans la console les items dans l'inventaire � nouveau.*/
	heap = malloc(HEAP_SIZE);
	Node* head = allocate(sizeof(Node));
	Item* inventaire[nombreMaxInventaire()];
	
	Item boots;
	boots.nom = "boots";
	boots.cost = 25;

	Item chainmail;
	chainmail.nom = "chainmail";
	chainmail.cost = 200;

	Item sword;
	sword.nom = "sword";
	sword.cost = 50;

#pragma region ajouter fiole
	//-Ajouter l'item nomm� "fiole" dans l'inventaire
	Item fiole;
	fiole.nom = "fiole";
	fiole.cost = 10;
#pragma endregion

#pragma region peupler inventaire
	//-Peupler l'inventaire d'un nombre al�atoire d'items en consid�rant que la "fiole" a d�j� �t� ajout�.
	srand(time(0));

#pragma endregion
	

	ajouter(head, &boots);
	ajouter(head, &chainmail);
	ajouter(head, &sword);
	ajouter(head, &fiole);

	//montrerCeQuiA(head);
	

	return 0;
}
