#pragma once

#include <stdlib.h>
#include <stdio.h>

#ifndef GLOBALS
#define GLOBALS
extern long resultat;
extern long meilleurecart;
extern int meilleurcalcul;
#endif

void affichesolution(int l);
void compte(int calcul, long resultat, long *meilleurecart, int *meilleurcalcul);

typedef struct
{
  long valeur1[16];
  char operation[16];
  long valeur2[16];
  long resultat[16];
} solution;

long * termeini;

long terme[16][16];

solution savesolution;
solution bestsolution;
