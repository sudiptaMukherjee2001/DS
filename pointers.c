#include <stdio.h>

int main() {
  int a = 5;
  int *ptra= &a;

  printf("********************ADDRESS OF a *******************\n\n");
  printf("This is address of a ===> %p",&a);
  printf("\nAddress of 'a' is store in a ptra pointer variable  ==> %p \n\n",ptra);
  printf("************************************************************************\n\n");

  printf("============ ADDRESS OF POINTER VARIABLE ptra============\n\n");
  printf("This is address of pointer variable ptra ==> %p\n\n",&ptra);
  printf("======================================================\n\n");

  printf("*******************VALUE OF a********************\n\n");
  printf("This is value of a ===> %d ",a);
  printf("\n Value of  'a' accessing using  Pointer variable ptra like this *ptr  ==> %d \n\n",*ptra);
  printf("***************************************\n\n");
  

}
