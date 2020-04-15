#include <stdio.h>

int main(void) {
  printf("***** Fast Exponentiation (Using Square and Multiply Method)***** \n\n");

  printf("y = a^x mod n\n");
  int y,a,x,n;
  printf("\nInput a: ");
  scanf("%d",&a);
  printf("Input x: ");
  scanf("%d",&x);
  printf("Input n: ");
  scanf("%d",&n);

  //convert n to binary
  int temp_bin[10];
  int i=0, j=0, k=0, temp=x, c=0;
  while(temp>0) {
    temp_bin[i] = temp%2;
    temp /= 2;
    i++;
    c++;
  }
  int len=c, bin[c];
  for(j=i-1 ; j>=0 ; j--) {
    bin[k] = temp_bin[j];
    k++;
  }
  printf("\n%d = (",x);
  for(i=0 ; i<len ; i++) {
    printf("%d", bin[i]);
  }
  printf(")base2\n\n");

  //make xi
  int xi[len];
  j=0;
  for(i=len-1 ; i>=0 ; i--) {
    xi[j] = bin[i];
    j++;
  }
  
  //make table

  printf("\n  i  |  xi |         Multiply          |     Square ");
  printf("\n-----+-----+---------------------------+----------------------\n");

  int ny = 1, na = a; 
  for(i=0 ; i<len ; i++) {

    printf(" %3d | %3d |",i,xi[i]);

    if(xi[i] == 1) {
      printf(" y = (%3dx%3d)mod%3d =",ny,na,n);
      ny = (ny*na)%n;
      printf(" %3d |",ny);
    }
    else {
      printf("            ---            |");
    }

    printf(" a = %3d^2 mod%d =",na,n);
    na = (na*na)%n;
    printf(" %3d ", na);

    printf("\n");

  }

  printf("\n\n");

  printf("y = %d",ny);

  printf("\n==> %d^%d mod%d = %d\n",a,x,n,ny);

  return 0;
}