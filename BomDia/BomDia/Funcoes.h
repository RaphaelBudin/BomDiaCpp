#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include "BomDia.h"

void carregarArquivo(std::vector<BomDia> &vBD);
void salvarArquivo(std::vector<BomDia> const &vBD);
int menuRetornaOpcao();
void addBomDia();
void mostrarBomDias(std::vector<BomDia> const &vBD);
void pesquisarBomDia(std::vector<BomDia> const &vBD);
void deletarBomDia(std::vector<BomDia> &vBD);


void sair(std::vector<BomDia> const &vBD);

#endif // !FUNCOES_H