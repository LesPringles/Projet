#include "algotechnique.h"
#include "action.h"

float Momentum(Stock stock, int i) // i est le jour actuel
{
    M = stock[i]->last - stock[i-12]->last;
    return M;

}
