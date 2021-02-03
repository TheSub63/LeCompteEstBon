#include "numgen.h"
#include "compte.h"
#include <limits.h>

int main(int argc, char *argv[])
{
  int i;
  int params = 6;

  long resultat=0;
  long meilleurecart=0;
  int meilleurcalcul=0;

  termeini=genNumbers(params);
  resultat=genRes();
   
  printf("Nombre a atteindre : %ld\n", resultat);
    
  printf("Liste de nombres : \n");
  for(i=0;i<params;i++)  
    printf("%ld\n", termeini[i]);
  
  for(i=0;i<params;i++)  
    terme[6][i]=termeini[i];

  meilleurecart=LONG_MAX;
  meilleurcalcul=INT_MAX;

	compte(params, resultat, &meilleurecart, &meilleurcalcul);

  affichesolution(meilleurcalcul);

	free(termeini);
  resetSolution();

  resultat=0;
  meilleurecart=0;
  meilleurcalcul=0;

  termeini=genNumbers(params);
  resultat=genRes();
   
  printf("Nombre a atteindre : %ld\n", resultat);
    
  printf("Liste de nombres : \n");
  for(i=0;i<params;i++)  
    printf("%ld\n", termeini[i]);
  
  for(i=0;i<params;i++)  
    terme[6][i]=termeini[i];

  meilleurecart=LONG_MAX;
  meilleurcalcul=INT_MAX;

	compte(params, resultat, &meilleurecart, &meilleurcalcul);

  affichesolution(meilleurcalcul);

	return(0);
}