#include <stdio.h>

int main()
{
	int arr[10], top = -1;
	int c;

	do {
		printf("\nOperation: \n1.Add Elements \n2.Remove Elements \n3.Display Elements \n4.Exit \n");
		scanf("%d", &c);

		switch (c)
		{
			case 1:
			{
				if (top >= 10)
				{
					printf("Stack Overflow\n");
				}
				else
				{
					int z, x;
					printf("Enter number of elements to be pushed\n");
					scanf("%d", &z);
					for (int i = 0; i < z; i++)
					{
						printf("Enter element\n");
						scanf("%d", &x);
						top++;
						arr[top] = x;
					}
				}
				break;
			}

			case 2: {
				if (top <= -1) {
					printf("Stack is Empty \n");
				}
				else {
					printf("Popped Element is %d", arr[top]);
					top--;
				}
				break;
			}

			case 3:
			{
				if (top >= 0)
				{
					printf("Elements are ");
					for (int i = 0; i <= top;i++)
					{
						printf("%d", arr[i], " - ");
					}

				}
				else
				{
					printf("Stack is Empty \n");
				}
				break;
			}

			case 4:
			{
				printf("Thanks For Using \n");
			}

		}

	} while (c != 4);
	return 0;
}
