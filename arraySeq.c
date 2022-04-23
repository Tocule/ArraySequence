#include<stdio.h>
#include <stdlib.h>

/*
 * ************* Maximum Points: 05 ***************** 
 *
 * ********** PENALTY: -7 (negative 7) ************** 
 *  In following cases you will get penalty
 *  (a) Not submitted, 
 *  (b) Copied, 
 *  (c) Late submission
 *  (d) Submission is not as per the instructions
 *
 * ***************** Instructions *******************
 * (1) Implement ALL methods without any changes in input arguments. You are
 *     NOT allowed to add or remove or change any arguments of method.
 * (2) DO NOT CHANGE any names of structure, functions or arguments.
 * (3) You can add helper methods / new methods. Add comments to describe its purpose.
 * (4) You can make assumptions if something is not clear. Make sure you write 
 *     your assumptions wherever required as comments. If you make assumptions but 
       HAVE NOT mentioned then it may lead to loss of points.
 * (5) While submitting the code DO NOT KEEP any code in main method. Also DO 
       NOT CHANGE filename while submitting the code.
 */


/* README
   This implementation of integer sequence uses static array. 
   Meaning array is exactly of size len. No buffer space.
   Every remove or insert will require you to initiate and 
   copy into NEW array of size len-1 or len+1 respectively.
*/

typedef struct ArraySeq 
{
  int *items;  // Array of length len
  int len;     // length of sequence
} ArraySeq;

/******Helper Functions******/

void print(ArraySeq *s)                        //Will print all the elements of the array
{
   printf("Your printed elements are : ");
   for(int i=0;i<s->len;i++)
   {
       printf("%d ",*(s->items+i));
   }
   printf("\n");
}

// Read 'len' number of integers and create ArraySeq from it.
// Return pointer to ArraySeq.

ArraySeq *build(int len)                         //Assumption:In main Function ArraySeq *p is created and function is called like this 
{                                                //p=build(length)
   ArraySeq *s;
   s=(ArraySeq *)malloc(sizeof(ArraySeq));
   s->items=(int *)malloc(len*sizeof(int));
   printf("Enter the elements\n");
   for(int i=0;i<len;i++)
   {
	   scanf("%d",s->items+i);
   }
   s->len=len;
   return(s);
}

// Replaces i th item in sequence with item 'x' 
 
void set_at(int i, int x, ArraySeq *s) 
{
   if(i>s->len || i<=0)              //supplied position i is supposed to be from  1 to size of array 
   {	                     
	printf("Error: Out of bounds\n");
        printf("Array size is %d\n",s->len);
   }
   else
   {
	i--;                         //Program will assume position 1 means 0 or 2 means 1 and so on
        *(s->items+i)=x;
   }	

}

int get_at(int i, ArraySeq s)       //Here for second argument the assumption is made that ArraySeq *s is passed since *s will pass underlying
{                                   //structure value hence value will be copied to normal struct variable s in the function(pass by value)   
   int b;
   if(i>s.len || i<=0)              //supplied position i is supposed to be from  1 to size of array 
   {
       printf("Error: Out of bounds Array size is %d\n",s.len);
       return(-9999);
   }
   else
   {
      i--;	                    //Program will assume position 1 means 0 or 2 means 1 and so on
      b=*(s.items+i);
      return(b); 
   }  
}

int length(ArraySeq s)           //Here for second argument the assumption is made that ArraySeq *s is passed since *s will pass underlying
{                                //structure value hence value will be copied to normal struct variable s in the function(pass by value)
   int b;
   b=s.len;
   return(b);
}


void insert_at(int i, int x, ArraySeq *s)  //It is assumed that we have to insert via copying into another array//
{	
  int j=s->len+1;
  int sequence[j];
  int k,c,t;
  if(i>j || i<=0)
  {
     printf("Error: Out of bounds Array size is %d\n",s->len);
  }
  else
  {
    i--;	  
    for(k=0;k<i;k++)
    {
      sequence[k]=*(s->items+k);
    }
    sequence[k]=x;
    t=k;
    for(c=k+1;c<j;c++)
    { 
      sequence[c]=*(s->items+t);
      t++;
    }
    s->len=j;
    s->items=(int *)malloc(j*sizeof(int));
    for(c=0;c<j;c++)
    {
      *(s->items+c)=sequence[c];
    }
  }    
     	      
}

int delete_at(int i, ArraySeq *s)    //It is assumed that we have to delete via copying into another array
{
   int j=s->len-1;
   int sequence[j];
   int k,c;
   if(i>s->len || i<=0)
   {
      printf("Error: Out of bounds Array size is %d\n",s->len);
      return(-9999);
   }
   else
   {
      i--;
      if(i==0)
      {
	 k=*(s->items+i);
         for(c=i+1;c<s->len;c++)
	 {
	    sequence[c-1]=*(s->items+c);
	 }
      }
      else if(i==j)
      {
	 k=*(s->items+i);
	 for(c=0;c<i;c++)
	 {
	    sequence[c]=*(s->items+c);
	 }
      }
      else
      {
	k=*(s->items+i);
        for(c=0;c<i;c++)
	{
	   sequence[c]=*(s->items+c);
        }
        for(c=i+1;c<s->len;c++)
	{
	   sequence[c-1]=*(s->items+c);
        }

      }
    s->len=j;
    s->items=(int *)malloc(j*sizeof(int));
    for(c=0;c<j;c++)
    {
      *(s->items+c)=sequence[c];
    }
    return(k);
   }
}

int main(void)
{

}
