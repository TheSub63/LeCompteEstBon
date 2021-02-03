#include "compte.h"

void affichesolution(int calcul)
{
  int i;

  printf("******************\n");
  for(i=6;i>calcul;i--)
    printf("%lu %c %lu = %lu\n",bestsolution.valeur1[i],bestsolution.operation[i],bestsolution.valeur2[i],bestsolution.resultat[i]);
  printf("******************\n");
}

void compte(int calcul)
{
  int i,j,k,n;
  long terme1=0,terme2=0;
  long ecart, r;

  ecart=resultat-terme[calcul][0];
  if(ecart<0)
    ecart=-ecart;
  if(ecart<=meilleurecart)
  {
    if(ecart<meilleurecart)
    {
      meilleurecart=ecart;
      bestsolution=savesolution;
      meilleurcalcul=calcul;
    }
    else  // (ecart==meilleurecart)
    {
      if(calcul>meilleurcalcul)
      {
        bestsolution=savesolution;
        meilleurcalcul=calcul;
      }
    }
  }

  if(calcul==1)
    return;

  for(i=0;i<calcul-1;i++)
  {
    for(j=i+1;j<calcul;j++)
    {
      terme1=terme[calcul][i];
      terme2=terme[calcul][j];


      n=1;
      for(k=0;k<calcul;k++)
      {
        if(k!=i && k!=j)
        {
          terme[calcul-1][n]=terme[calcul][k];
          n++;
        }
      }

      terme[calcul-1][0]=terme1+terme2;
      savesolution.valeur1[calcul]=terme1;
      savesolution.operation[calcul]='+';
      savesolution.valeur2[calcul]=terme2;
      savesolution.resultat[calcul]=terme[calcul-1][0];
      compte(calcul-1);
      _Bool check = (terme1!=1 && terme2!=1);
      if(check)
      {
        terme[calcul-1][0]=terme1*terme2;
        savesolution.operation[calcul]='*';
        savesolution.resultat[calcul]=terme[calcul-1][0];
        compte(calcul-1);
		     		  
				if(terme1>=terme2)
				{
					terme[calcul-1][0]=terme1-terme2;
					if(terme[calcul-1][0])
					{
						savesolution.operation[calcul]='-';
				    savesolution.resultat[calcul]=terme[calcul-1][0];
						compte(calcul-1);
					}
					r=terme1%terme2;
					if(!r)
					{
	                terme[calcul-1][0]=terme1/terme2;
				    savesolution.operation[calcul]='/';
						savesolution.resultat[calcul]=terme[calcul-1][0];
						compte(calcul-1);
					}
				}
				else
				{
	                terme[calcul-1][0]=terme2-terme1; 
					savesolution.valeur1[calcul]=terme2;
					savesolution.operation[calcul]='-';
					savesolution.valeur2[calcul]=terme1;
					savesolution.resultat[calcul]=terme[calcul-1][0];
					compte(calcul-1);
					r=terme2%terme1;

					if(!r)
					{
	                    terme[calcul-1][0]=terme2/terme1;
						savesolution.operation[calcul]='/';
						savesolution.resultat[calcul]=terme[calcul-1][0];
						compte(calcul-1);
					}
				}
			}
	    else if(terme1>=terme2)
      {
        terme[calcul-1][0]=terme1-terme2;
        if(terme[calcul-1][0])
        {
          savesolution.operation[calcul]='-';
          savesolution.resultat[calcul]=terme[calcul-1][0];
          compte(calcul-1);
        }
      }
      else
      {
        terme[calcul-1][0]=terme2-terme1;
        savesolution.valeur1[calcul]=terme2;
        savesolution.operation[calcul]='-';
        savesolution.valeur2[calcul]=terme1;
        savesolution.resultat[calcul]=terme[calcul-1][0];
        compte(calcul-1);
      }
    }
  }
}