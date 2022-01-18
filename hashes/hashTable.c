#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

/*
 * @key : The key string of a pair
 * The key is unique in the HashTable
 *
 * @value : The value corresponding to a key
 * A value is not unique. It can correspond to several keys
 *
 * @next : A pointer to the next node of the List
 */
typedef struct List
{
	char *key;
	char *value;
	struct List *next;
} List;

/*
 * @size : The size of the array
 *
 * @array : An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct HashTable
{
	unsigned int size;
	List **array;
} HashTable;

int print_char(char c)
{
	return (_write(1, &c, 1));
}
void print_str(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		print_char(str[i]);
	}
}
void print_num(int n)
{
	if (n >= 10) {
		print_num(n / 10);
	}
	print_char(n % 10 + 48);
}

/*
 * @key : The key to hash
 *
 * @size : The size of the hashtable
 *
 * @return : An integer N like 0 <= N < @size
 * This integer represents the index of @key in an array of size @size
 */
unsigned int hash(const char *key, unsigned int size)
{
	unsigned int hash = 0, i = 0;

	while (key && key[i])
		hash = (hash + key[i++]) % size;
		
	return (hash);
}

/*
 * str_cmp1() - Compare two strings to determine if they are identical. Ensures
 * that each char in the strings are the same, and that they are of the same
 * length.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Zero if the strings are identical, one otherwise.
 */
int str_cmp1(char *s1, char *s2)
{
	int i;
	int j = 0;

	for (i = 0; s1[i] != '\0'; ++i) {
		if (s1[j] != s2[j] || s1[j + 1] != s2[j + 1]) {
			return 1;
		}
		j++;
	}
	return 0;
}

/*
 * str_cmp() - Compare two strings to determine if they are identical. Ensures
 * that each char in the strings are the same, and that they are of the same
 * length.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Zero if the strings are identical, one otherwise.
 */
int str_cmp(char *s1, char *s2)
{
	int i;
	int j = 0;

	for (i = 0; s1[i] != '\0'; ++i) {
		if (s1[j] != s2[j] || s1[j + 1] != s2[j + 1]) {
			return 1;
		}
		j++;
	}
	return 0;
}

/*
 * node_handler() - If the index item is a linked list, traverse it to ensure
 * that there is not already an item with the key passed. If there is,
 * reassign the value of the prexisting node to the current instead of adding
 * the new node.
 * @hashtable: The hashtable of Lists.
 * @node: The linked list to add a node to or update.
 *
 * Return: Void.
 */
void node_handler(HashTable *hashtable, List *node)
{
	unsigned int i = hash(node->key, hashtable->size);
	List *tmp = hashtable->array[i];

	if (hashtable->array[i] != NULL) {
		tmp = hashtable->array[i];
		while (tmp != NULL) {
			if (str_cmp(tmp->key, node->key) == 0) {
				break;
			}
			tmp = tmp->next;
		}
		if (tmp == NULL) {
			node->next = hashtable->array[i];
			hashtable->array[i] = node;
		}
		else {
			free(tmp->value);
			tmp->value = _strdup(node->value);
			free(node->value);
			free(node->key);
			free(node);
		}
	}
	else {
		node->next = NULL;
		hashtable->array[i] = node;
	}
}

HashTable *ht_create(unsigned int size)
{
	HashTable *ht;

	if (size < 1)
		return NULL;

	ht = malloc(sizeof(HashTable));
	if (ht == NULL)
		return (NULL);

	ht->array = (List**)malloc(size * sizeof(List));
	if (ht->array == NULL)
		return (NULL);

	memset(ht->array, 0, size * sizeof(List));

	ht->size = size;

	return ht;
}

void ht_free(HashTable *hashtable)
{
	List *tmp;
	unsigned int i;

	if (hashtable == NULL) {
		return;
	}

	for (i = 0; i < hashtable->size; ++i) {
		if (hashtable->array[i] != NULL) {
			/* Traverse the list and free the nodes. */
			while (hashtable->array[i] != NULL) {
				tmp = hashtable->array[i]->next;
				free(hashtable->array[i]->key);
				free(hashtable->array[i]->value);
				free(hashtable->array[i]);
				hashtable->array[i] = tmp;
			}
			free(hashtable->array[i]);
		}
	}
	free(hashtable->array);
	free(hashtable);
}

char *ht_get(HashTable *hashtable, const char *key)
{
	char *key_cp;
	unsigned int i;
	List *tmp;

	if (hashtable == NULL) {
		return NULL;
	}
	key_cp = _strdup(key);
	i = hash(key, hashtable->size);
	tmp = hashtable->array[i];

	while (tmp != NULL) {
		if (str_cmp1(tmp->key, key_cp) == 0) {
			break;
		}
		tmp = tmp->next;
	}
	free(key_cp);

	if (tmp == NULL) {
		return NULL;
	}
	return tmp->value;
}

int ht_put(HashTable *hashtable, const char *key, const char *value)
{
	List *node;

	if (hashtable == NULL)
		return 1;

	node = malloc(sizeof(List));
	if (node == NULL)
		return (1);

	node->key = _strdup(key);
	node->value = _strdup(value);
	node_handler(hashtable, node);

	return 0;
}

int print_hashtable(HashTable *ht) {
	unsigned int i;
	List *listptr;
	for (i = 0; i < ht->size; ++i) {
		print_num(i);
		print_str("\n");

		listptr = ht->array[i];
		print_str("\t--------\n");

		while (listptr != NULL) {
			print_str("\tkey: ");
			print_str(listptr->key);
			print_str("\n\tval: ");
			print_str(listptr->value);
			listptr = listptr->next;
			print_str("\n\t--------\n");
		}
		print_str("\tNULL\n\t--------\n");
	}
	return 0;
}

int main(void) {
	HashTable *ht;
	ht = ht_create(10);

	if (ht == NULL)
		return 1;

	ht_put(ht, "1", "1");
	ht_put(ht, "2", "2");
	ht_put(ht, "3", "3");
	ht_put(ht, "4", "4");
	ht_put(ht, "5", "5");
	ht_put(ht, "4", "NEW VAL 4");
	print_hashtable(ht);
	print_str(ht_get(ht, "4"));
	print_str("\n");
	ht_free(ht);
	system("pause");
	return 0;
}
