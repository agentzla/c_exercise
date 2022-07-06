#include <stdio.h>
#include <stdlib.h>
#define size 3
#define ncolumns 20

typedef struct typeproduct {
  int code;
  char name[ncolumns];
  float price;
}Tproduct;

Tproduct *print(Tproduct *);
Tproduct *read(Tproduct *);

int main() {
  Tproduct *product = (Tproduct *)(malloc(size*sizeof(Tproduct)));
  product = print(read(product));
  free(product);
  return (0);
}

Tproduct *read(Tproduct *product) {
  int i;
  Tproduct *initPTR = product;
  for (i=0;i<size;i++) {
    printf("Type product %d's name: ", i+1);
    fgets(product->name,ncolumns,stdin);
    printf("Type product %d's price: ", i+1);
    scanf("%f",&product->price);
	setbuf(stdin, '\0');
    (*product).code = i+1;
    product++;
  }
  return(initPTR);
}

Tproduct *print(Tproduct *product) {
  int i;
  Tproduct *initPTR = product;
  for (i=0;i<size;i++) {
    printf("\n\n Product %d's name: %s", i+1, product->name);
    printf("\nProduct %d's price: $%.2f", i+1, product->price);
    printf("\nProduct %d's code: %d", i+1, product->code);
    product++;
  }
  return(initPTR);
}