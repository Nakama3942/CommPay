#include <iostream>
#include "CoPa.h"
using namespace std;

int main()
{
    entry intro;
    check provka;
    tariff tarcoef;
    FILE *coef;
    coef = fopen("/usr/local/share/Options.conf", "r+");
    fscanf(coef, "%f %f %f %f %f %f %f %i", &tarcoef.coefficient[0], &tarcoef.coefficient[1], &tarcoef.coefficient[2], &tarcoef.coefficient[3], &tarcoef.coefficient[4], &tarcoef.coefficient[5], &tarcoef.coefficient[6], &tarcoef.KodValut);
    for (;;)
    {
        intro.instruction();
        intro.rate();
        provka.outlet(tarcoef, coef);
        intro.ending();
    }
    fclose(coef);
    return 0;
}
