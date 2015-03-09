#include "algotechnique.h"
#include "action.h"


// Soustraction du cours actuel au cours d'il y a 12 jours
float Momentum(Stock *stock, StockHisto **tabStockHisto, size_t tailleTab)
{
    float M = (*stock)->last - (*tabStockHisto)[tailleTab-12]->close;
    return M;
}
