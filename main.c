#include "numgen.h"
#include "compte.h"


long resultat=0;
long meilleurecart=0;
int meilleurcalcul=0;

int main(int argc, char *argv[])
{
  int i;
  int params = 6;

  termeini=genNumbers(params);
  resultat=genRes();
   
  printf("Nombre a atteindre : %ld\n", resultat);
    
  printf("Liste de nombres : \n");
  for(i=0;i<params;i++)  
    printf("%ld\n", termeini[i]);
  
  for(i=0;i<params;i++)  
    terme[6][i]=termeini[i];
  
  for(i=0;i<params;i++)  // initialise terme[][]
    terme[6][i]=termeini[i];

  meilleurecart=LONG_MAX;
  meilleurcalcul=INT_MAX;

	compte(params);

  affichesolution(meilleurcalcul);

	free(termeini);

	return(0);
}