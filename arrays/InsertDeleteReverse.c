#include <stdio.h>

const int MAKS = 20;

void array_print(int *a, int size)
{
	while (size--)
		printf("%d ", *a++);
}

int array_insert(int *a, int size, int element, int position)
{
	if (position >= size)
	{
		fprintf(stderr, "\narray_insert: The specified position %i is not less than the"
			" size of the array which is %i\n", position, size);
		return 0;
	}
	int *p = a + position; //the pointer to the location where the new element will get inserted
	a += size; //a points to one past the last element of original array
	while (a > p)
	{
		*(a) = *(a - 1);
		a--;
	}
	*a = element;
	return 1;
}

int array_delete(int *a, int size, int position)
{
	if (position >= size)
	{
		fprintf(stderr, "\narray_delete: The specified position %i is not less than the"
			" size of the array which is %i\n", position, size);
		return 0;
	}
	int *last = a + size - 1; // points to the last element
	a += position; //a now points to the position of the deletion
	while (a < last)
	{
		*(a) = *(a + 1);
		a++;
	}
	return 1;
}

void array_reverse(int *a, int size)
{
	for (int i = 0, t; i < size/2; i++)
	{
		t = a[i];
		a[i] = a[size - i - 1];
		a[size - i - 1] = t;
	}
}

void input_array(int *a, int size)
{
	while (size--)
		scanf("%d", a++);
}

int main() {

	int *a = malloc(MAKS * sizeof(int));

	printf("How many numbers do you wanto start with?\n");
	int s;
	scanf("%d", &s);
	printf("Enter the array:");
	input_array(a, s);
	
	do {
		int i;
		printf("\nWhat do you want to do?\n1 for Insert an element.\n2 for Delete an element \n3 for Reverse \n4 for Display \nOther for Exit \n");
		scanf("%d", &i);
		
		switch (i)
		{
			case 1:
			{
				printf("Enter the position (zero-based):");
				int p;
				scanf("%d", &p);
				printf("Enter the element to be inserted : ");
				int e;
				scanf("%d", &e);

				if (array_insert(a, s, e, p))
				{
					s++;
					printf("Done!\n");
				}
				else
					printf("Insertion Failed!\n");
				break;
			}
			case 2:
			{
				printf("Enter the position (zero-based) at which you want to delete the element:");
				int p;
				scanf("%d", &p);
				if (array_delete(a, s, p))
				{
					s--;
					printf("Done!\n");
				}
				else
					printf("Deletion Failed!\n");
				break;
			}
			case 3:
			{
				array_reverse(a, s);
				printf("Done!\n");
				break;
			}
			case 4:
			{
				printf("\n");
				array_print(a, s);
				printf("\n\n");
				break;
			}
			default:
				return 0;
		}
	} while (1);
	return 0;
}
