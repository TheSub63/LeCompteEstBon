# Compilation

Du fait de nos environnements de travail différents (Clément travaillait sur un PC Windows alors que j'utilisais un système Linux), il n'avait pas besoin d'ajouter la librairie `limits.h`, il demandait la valeur `MAX_INT` et cela fonctionnait pour lui à la compilation mais pas pour moi.

# Correction des erreurs

Après avoir compilé, j'ai utilisé Valgrind pour pouvoir analysé les potentielles erreus et les fuites mémoires. Si il n'y avait pas de fuites mémoires, il y avait beaucoup d'erreurs.

```
==4926== 
==4926== HEAP SUMMARY:
==4926==     in use at exit: 0 bytes in 0 blocks
==4926==   total heap usage: 2 allocs, 2 frees, 4,103 bytes allocated
==4926== 
==4926== All heap blocks were freed -- no leaks are possible
==4926== 
==4926== Use --track-origins=yes to see where uninitialised values come from
==4926== For lists of detected and suppressed errors, rerun with: -s
==4926== ERROR SUMMARY: 2781100 errors from 145 contexts (suppressed: 0 from 0)
```

Je me suis vite rendu compte que ces erreurs étaient dûes à un mauvais `malloc`, que j'ai modifié :

``` C
# L'ancienne version du malloc :
long * numbers = (long *) malloc (n + 1);

# La nouvelle version du malloc :
long * numbers = (long *) malloc (sizeof(long) * n);
```

Après cette simple correction, il n'y avait ni d'erreurs ni de fuite de mémoire.

# Analyse du code avec SonarQube

Pour analyser le code de Clément, j'ai voulu utiliser SonarQube, qui est un outili qui permet, avec des métriques d'analyser la qualité d'un code. SonarQube propose plusieurs versions, une version communitaire, une version pour les développeurs et une version entreprise. Si la version communautaire est gratuite, elle ne permet pas d'analyser le C, et il faut se tourner vers une version payante. 

Heureusement, j'ai pu trouver un plugin open-source sur GitHub pour pouvoir analysé le code depuis SonarQube. Mettre tout en place pour pouvoir lancer une analyse m'a pris beaucoup de temps, et les résultats étaient quelque peu décevant :

![](images/sonarqube1.png)

J'ai modifié le code pour pouvoir ajouté un bug, mais celui-ci n'a pas été analysé par SonarQube, j'ai donc décidé d'abandonner l'idée d'utiliser SonarQube, ayant déjà passé beaucoup de temps dessus et n'ayant pas trouvé de résultats pertinents.

# Tests unitaires

Pour les tests unitaires, je choisi d'utiliser la biblithèque utilisée pour les TP de C de première année (teZZt) écrite M. Yon et M. Bachelet. Elle a l'avantage d'étre très légère et facile à intégrer, puisqu'elle est contenue dans un simple `.h`. Je récupère ce `.h` depuis le répertoire git d'un TP de C de ZZ1.

