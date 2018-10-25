#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
 printf("How many elements are in the first massive?\n");
 int n1 = GetInt();
 int arr1[n1];
 if(n1<=0)
 {}
 else
 {
  printf("Please, type elements of your massive.\n");
  for(int i=0; i<n1; i++)
  {
   arr1[i] = GetInt();
  }
 }
 printf("How many elements are in the second massive?\n");
 int n2 = GetInt();
 int arr2[n2];
 if(n2<=0)
 {}
 else
 {
  printf("Please, type elements of your massive.\n");
  for(int i=0; i<n2; i++)
  {
   arr2[i] = GetInt();
  }
 } 
 //making copies of massives (1 of the first and 2 of the second).
 int PA1[n1];
 int PA3[n2];
 int PA4[n2];
 //PA means Pseudo Array.
 for(int i=0;i<n1;i++)
 {
  PA1[i] = arr1[i];
 }
 for(int i=0;i<n2;i++)
 {
  PA3[i] = arr2[i];
  PA4[i] = arr2[i];
 }
 //calculating power of the first massive.
  int count = 0;
 for(int i=0; i<n1; i++) 
 {
  int i1 = 0;
  for(int j=0; j<n1; j++) 
  {
   if(PA1[i]!=PA1[j])
   {
   i1++;
   }
  }
 if (i1==(n1-1)) 
  {
   count++;
  }
 else
  {
    PA1[i] = -1337;
    continue;
  }   
 }
 if(count==0)
  printf("The first massive have no power!\n");
 else
  printf("Power of the first massive is: %i.\n Boolean: %f.\n", count, pow(2,count));
 //and the same for the second massive.
 int counter = 0;
 for(int i=0; i<n2; i++) 
 {
  int i1 = 0;
  for(int j=0; j<n2; j++) 
  {
   if(PA3[i]!=PA3[j])
   {
   i1++;
   }
  } 
 if (i1==(n2-1)) 
  {
   counter++;
  }
 else
  {
    PA3[i] = -1337;
    continue;
  }   
 }
 if(counter==0)
  printf("The second massive have no power!\n");
 else
  printf("Power of the second massive is: %i.\n Boolean: %f.\n", counter, pow(2,counter));
 //showing of massives intersection.
 int size;
 if(n1>n2)
  size = n1;
 else
  size = n2;
int intersection[size];
 int number = 0;
 for(int i=0;i<n1;i++)
 {
  int i2=0;
  int element;
  for(int j=0;j<n2;j++)
  {
   if(arr1[i]==PA4[j])
   {
    i2++;
    element = arr1[i];
    PA4[j] = -1337;
   }
  }
  if(i2>0)
  {
   intersection[number]=element;
   number++;
  }
 }
 if(number==0)
  printf("Impossible to get Intersection of these massives\n");
 else
 {
  printf("Intersection of massives is:\n{");
  for(int i=0; i<number; i++)
  {
   printf("%i,",intersection[i]);
  }
  printf("}.\n");
 }
 //showing of this intersection in union with the first massive.
 int number1=number;
 for(int i=0;i<n1;i++)
 {
  int index=0;
  for(int j=0;j<number1;j++)
  {
   if(arr1[i]!=intersection[j])
   index++;
  }
  if(index==number1)
  {
   intersection[number]=arr1[i];
   number++;
  }
 }
 if(number==0)
  printf("Impossible to get Union of the first massive and the Intersection\n");
 else
 {
  printf("Union of intersection and the first massive is:\n{");
  for(int i=0; i<number; i++)
  {
   printf("%i,",intersection[i]);
  }
  printf("}.\n");
 }
}
