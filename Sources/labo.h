#include <assert.h>
#include <stdint.h>

#define HEAP_SIZE 1024 * 1024
extern uint8_t* heap;
extern size_t heap_top;

static void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}

typedef struct {
	char* nom;
	int cost;
}Item;

typedef struct Node_t Node;

struct Node_t
{
	void* data;
	Node* next;
	Node* prev;
};

void ajouter(Node* head, void* item );

void enlever(Node* head, void* nom);

void trier(Node* head);

Node* trouverItemPos(Node* head, void* pos);

int trouverItemNom(Node* head, char* name);

int qteItems(Node* head);

void ajouterRandom(Node head);

void lireFichier();

void ajouterFromFile();

