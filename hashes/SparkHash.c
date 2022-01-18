#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct _list_t_ {
	char *string;
	struct _list_t_ *next;
} list_t;

typedef struct _hash_table_t_ {
	int size;       /* the size of the table */
	list_t **table; /* the table elements */
} hash_table_t;

hash_table_t *create_hash_table(int size)
{
	hash_table_t *new_table;

	if (size < 1) return NULL; /* invalid size for table */

	/* Attempt to allocate memory for the table structure */
	if ((new_table = malloc(sizeof(hash_table_t))) == NULL) {
		return NULL;
	}

	/* Attempt to allocate memory for the table itself */
	if ((new_table->table = malloc(sizeof(list_t *) * size)) == NULL) {
		return NULL;
	}

	/* Initialize the elements of the table */
	for (int i = 0; i < size; i++) new_table->table[i] = NULL;

	/* Set the table's size */
	new_table->size = size;

	return new_table;
}

unsigned int hash(hash_table_t *hashtable, char *str)
{
	unsigned int hashval=0;

	/* for each character, we multiply the old hash by 17 and add the current
	 * character.
	 */
	for (; *str != '\0'; str++) 
		hashval = *str + hashval*17;

	/* we then return the hash value mod the hashtable size so that it will
	 * fit into the necessary range
	 */
	return hashval % hashtable->size;
}

list_t *get_string(hash_table_t *hashtable, char *str)
{
	list_t *list;
	unsigned int hashval = hash(hashtable, str);

	/* Go to the correct list based on the hash value and see if str is
	 * in the list.  If it is, return a pointer to the list element.
	 * If it isn't, the item isn't in the table, so return NULL.
	 */
	list = hashtable->table[hashval];
	for (; list != NULL; list = list->next) {
		if (strcmp(str, list->string) == 0) return list;
	}
	printf("%s isnt in the list", str);
	return NULL;
}

int add_string(hash_table_t *hashtable, char *str)
{
	list_t *new_list, *current_list;
	unsigned int hashval = hash(hashtable, str);

	/* Attempt to allocate memory for list */
	if ((new_list = malloc(sizeof(list_t))) == NULL) return 1;

	/* Does item already exist? */
	current_list = get_string(hashtable, str);
	/* item already exists, don't insert it again. */
	if (current_list != NULL) {
		printf("%s already in the list, don't insert it again.\n", str);
		return 2;
	}
	
	/* Insert into list */
	new_list->string = _strdup(str);
	new_list->next = hashtable->table[hashval];
	printf(", %s added to list\n", str);
	hashtable->table[hashval] = new_list;

	return 0;
}

void free_table(hash_table_t *hashtable)
{
	int i;
	list_t *list, *temp;

	if (hashtable == NULL) return;

	/* Free the memory for every item in the table, including the
	 * strings themselves.
	 */
	for (i = 0; i < hashtable->size; i++) {
		list = hashtable->table[i];
		while (list != NULL) {
			printf("%s ",list->string);
			temp = list;
			list = list->next;
			free(temp->string);
			free(temp);
		}
	}

	/* Free the table itself */
	free(hashtable->table);
	free(hashtable);
}

int main()
{
	hash_table_t *my_hash_table = create_hash_table(5);

	add_string(my_hash_table, "elma");
	add_string(my_hash_table, "armut"); 
	add_string(my_hash_table, "üzüm");
	add_string(my_hash_table, "abbas");
	add_string(my_hash_table, "elmas");
	add_string(my_hash_table, "elma");/* item already exist error*/

	printf(get_string(my_hash_table, "elmas")->string);

	free_table(my_hash_table);
	system("pause");
	return 0;
}
