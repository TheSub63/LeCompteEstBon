#include "teZZt.h"
#include "../compte.h"
#include "../numgen.h"

BEGIN_TEST_GROUP(numgen)

TEST(numgen) {
    int i;
    long * numbers = genNumbers(10);
    for(i = 0; i < 10; i++)
        CHECK(numbers[i]);
}

END_TEST_GROUP(numgen)

BEGIN_TEST_GROUP(calcul)

TEST(tester_resultats) {
    int i;
    int meilleurcalcul = 0;
    long meilleurecart = 0;
    long resultat = 678;
    termeini = (long *) malloc (6 * sizeof(long));
    for(i = 0; i < 6; i++)
        termeini[i] = genrand_int32_pos()%100;
    for(i=0;i<6;i++)  
        terme[6][i]=termeini[i];
    compte(6, resultat, &meilleurecart, &meilleurcalcul);
    for(i = 6; i > meilleurcalcul; i--) {
        switch(bestsolution.operation[i]) {
            case '/': 
                CHECK(bestsolution.valeur1[i] / bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
            case '*':
                CHECK(bestsolution.valeur1[i] * bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
            case '+':
                CHECK(bestsolution.valeur1[i] + bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
            case '-':
                CHECK(bestsolution.valeur1[i] - bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
        }
    }
    affichesolution(meilleurcalcul);
    free(termeini);
    resetSolution();
}

TEST(autres_nombres) {
    int i;
    int meilleurcalcul = 0;
    long meilleurecart = 0;
    long resultat = 60;
    termeini = genNumbers(6);
    for(i=0;i<6;i++)
        terme[6][i]=termeini[i];
    compte(6, resultat, &meilleurecart, &meilleurcalcul);
    for(i = 6; i > meilleurcalcul; i--) {
        switch(bestsolution.operation[i]) {
            case '/': 
                CHECK(bestsolution.valeur1[i] / bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
            case '*':
                CHECK(bestsolution.valeur1[i] * bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
            case '+':
                CHECK(bestsolution.valeur1[i] + bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
            case '-':
                CHECK(bestsolution.valeur1[i] - bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
        }
    }
    affichesolution(meilleurcalcul);
    free(termeini);
}

TEST(resultat_inatteignable) {
    int i;
    int meilleurcalcul = 0;
    long meilleurecart = 0;
    long resultat = 997;
    termeini = genNumbers(6);
    for(i=0;i<6;i++)
    {
        termeini[i] = i + 1;
        terme[6][i]=termeini[i];
    }
    compte(6, resultat, &meilleurecart, &meilleurcalcul);
    for(i = 6; i > meilleurcalcul; i--) {
        switch(bestsolution.operation[i]) {
            case '/': 
                CHECK(bestsolution.valeur1[i] / bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
            case '*':
                CHECK(bestsolution.valeur1[i] * bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
            case '+':
                CHECK(bestsolution.valeur1[i] + bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
            case '-':
                CHECK(bestsolution.valeur1[i] - bestsolution.valeur2[i] == bestsolution.resultat[i]);
                break;
        }
    }
    affichesolution(meilleurcalcul);
    free(termeini);
}

END_TEST_GROUP(calcul)

int main(void) {
    RUN_TEST_GROUP(numgen);
    RUN_TEST_GROUP(calcul);
    return 0;
}