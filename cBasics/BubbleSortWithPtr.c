#include <stdio.h>
#define SIZE 10
void bubbleSort( int *, const int );
void swap( int *, int * );
int main()
{
   
   int a[SIZE] = { 2, 6, 3, 12, 10, 8, 89, 68, 45, 37 };
   int i;
   printf( "Data items in original order\n" );
   for ( i = 0; i < SIZE; i++ )
      printf( "%4d", a[ i ] );
   bubbleSort( a, SIZE );  
   printf( "\nData items in ascending order\n" );
   for ( i = 0; i < SIZE; i++ )
      printf( "%4d", a[ i ] );   
   printf( "\n" );
   return 0;
}
void bubbleSort( int *array, const int size )
{
   int pass, j; 
   for ( pass = 0; pass < size - 1; pass++ )
      for ( j = 0; j < size - 1; j++ )
         if ( array[ j ] > array[ j + 1 ] )
            swap( &array[ j ], &array[ j + 1 ] );
}
void swap( int *element1Ptr, int *element2Ptr )
{
   int hold = *element1Ptr;
   *element1Ptr = *element2Ptr;
   *element2Ptr = hold;
}
