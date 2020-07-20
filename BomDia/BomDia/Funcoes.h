#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include "BomDia.h"

void carregarArquivo(std::vector<BomDia> &vBD);
void salvarArquivo(std::vector<BomDia> &vBD);
int menuRetornaOpcao();
void addBomDia();

#endif // !FUNCOES_H


