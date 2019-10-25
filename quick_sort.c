#include<stdio.h>
void quicksort(int array[],int first,int last);
int partition(int array[],int low,int high);
void swap(int array[],int num1, int num2);
void display(int array[],int n);
int count;
int main(){
   int i, array[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&array[i]);
 printf("Order of UnSorted elements: ");
   display( array,count);
   quicksort(array,0,count-1);

   printf("Order of Sorted elements: ");
   display( array,count);


   return 0;
}
 /* The main function that implements QuickSort
    array[] --> array to be sorted,
    low  --> Starting index,
    high  --> Ending index */
void quicksort(int array[],int low,int high)
{
    int pi;
    if(low<high)
    {
         /* pi is partitioning index after partitioning */
        pi=partition(array,low,high);
        printf("partitioning index  %d\n",pi);
        // Separately sort elements before
        // partition and after partition
        quicksort(array, low, pi - 1); // Recursively sort elements left of pivot
        quicksort(array, pi + 1, high);   // and elements right of pivot
    }
}
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller to left of pivot and
    all greater elements to right of pivot */
int partition(int array[],int first,int last){
   int i, j, pivot;
      pivot=array[first];  // pivot value
       printf("\nlow %d high %d  pivot value %d\n",first,last,pivot);
      i=first; // Index of first element
      j=last;// Index of last element

      while(i<j){
            /* If current element is smaller than or
         equal to pivot and i<j then increment the i*/
         while(array[i]<=pivot&&i<j)
            i++;
       /* If last element is greater than  pivot then decrement the j*/
         while(array[j]>pivot)
            j--;
            /*exchange i with j if condition match*/
         if(i<j){
            printf(" item swapped :%d,%d\n", array[i],array[j]);
           swap(array,i,j);
         }
      }
printf(" pivot swapped :%d,%d\n", array[first],array[j]);
  // swap(array,i,last);
  /*exchange pivot with j at the completion
    of loop*/
  array[first]=array[j];
  array[j]=pivot;
   printf("Updated Array: ");
   display(array,count);
return j;
}
// A utility function to swap two elements
void swap(int array[],int num1, int num2) {
  int  temp;
  temp=array[num1];
            array[num1]=array[num2];
            array[num2]=temp;
}

/*  function to print an array */
void display(int array[],int n) {
   int i;
   printf("[");

   // navigate through all items
   for(i = 0;i < n;i++) {
      printf("%d ",array[i]);
   }

   printf("]\n");
}
