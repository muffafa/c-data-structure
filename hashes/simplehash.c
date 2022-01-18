#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry_s {
	int not_empty;
	char key[7];
	char val[16];
}entry_t;

typedef struct ht_s {
	int size;
	entry_t *tab;
}ht_t;

/* Create a new ht. */
ht_t *ht_create(int size) {
	ht_t *ht = NULL;

	if (size < 1) return NULL;

	/* Allocate the tab itself. */
	if ((ht = malloc(sizeof(ht_t))) == NULL)
		return NULL;
	/* Allocate pointers to the head nodes. */
	if ((ht->tab = malloc(size * sizeof(entry_t))) == NULL)
		return NULL;
	for (int i = 0; i < size; i++)
		memset(&ht->tab[i], 0, sizeof(entry_t));

	ht->size = size;
	return ht;
}

/* Hash a string for a particular hash tab. */
int ht_hash(ht_t *ht, char *key) {
	int hv = 0;

	/* Convert our string to an integer */
	for (int i = 0; i < strlen(key); i++)
		hv += key[i];
	return hv % ht->size;
}

/* Insert a key-val pair into a hash tab. */
void ht_set(ht_t *ht, char *key, char *val) {
	int ind = ht_hash(ht, key);

	for (int i = 0; i < ht->size; i++)
		if (!ht->tab[i].not_empty) {
			ht->tab[i].not_empty = 1;
			strcpy(ht->tab[i].key, key);
			strcpy(ht->tab[i].val, val);
			return;
		}
	/*for (int i = 0; i < ind; i++)
		if (!ht->tab[i].not_empty) {
			ht->tab[i].not_empty = 1;
			strcpy(ht->tab[i].key, key);
			strcpy(ht->tab[i].val, val);
			return;
		}*/
}

/* Retrieve a key-val pair from a hash tab. */
char *ht_get(ht_t *ht, char *key) {
	int ind = ht_hash(ht, key);


	for (int i = 0; i < ht->size; i++)
		if ((ht->tab[i].not_empty) && !strcmp(ht->tab[i].key, key))
			return ht->tab[i].val;
	/*for (int i = 0; i < ind; i++)
		if ((ht->tab[i].not_empty) && !strcmp(ht->tab[i].key, key))
			return ht->tab[i].val;*/
	return "not found";
}

int main(void) {

	ht_t *ht = ht_create(5);

	ht_set(ht, "key1", "inky");
	ht_set(ht, "key2", "pinky");
	ht_set(ht, "key2", "finky");
	ht_set(ht, "key3", "blinky");
	ht_set(ht, "kez2", "floyd");

	printf("%s\n", ht_get(ht, "key1"));
	printf("%s\n", ht_get(ht, "key2"));
	printf("%s\n", ht_get(ht, "key2"));
	printf("%s\n", ht_get(ht, "key3"));
	printf("%s\n", ht_get(ht, "kez2"));
	printf("%s\n", ht_get(ht, "key4"));

	system("pause");
	return 0;
}
