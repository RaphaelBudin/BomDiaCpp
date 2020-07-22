#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include "BomDia.h"

void carregarArquivo(std::vector<BomDia> &vBD);
void salvarArquivo(std::vector<BomDia> const &vBD);
int menuRetornaOpcao();
void addBomDia();


void sair(std::vector<BomDia> const &vBD);

#endif // !FUNCOES_H