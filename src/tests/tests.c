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

TEST(avec_zeros) {
    int i;
    int meilleurcalcul = 0;
    long meilleurecart = 0;
    long resultat = 678;
    termeini = (long *) malloc (6 * sizeof(long));
    for(int i = 0; i < 6; i++)
        termeini[i] = genrand_int32_pos()%100;;
    compte(6, resultat, &meilleurecart, &meilleurcalcul);
}

END_TEST_GROUP(calcul)

int main(void) {
    RUN_TEST_GROUP(numgen);
    RUN_TEST_GROUP(calcul);
    return 0;
}