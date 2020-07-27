#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include "BomDia.h"

void carregarArquivo(std::vector<BomDia> &vBD);
void salvarArquivo(const std::vector<BomDia> &vBD);
int menuRetornaOpcao();

void addBomDia();

const void mostrarVetorBomDias(const std::vector<BomDia> &vBD);
const void mostrarBomDia(const std::vector<BomDia> &vBD);
const std::string retornarBomDia(std::vector<BomDia> &vBD, const int posicaoVetor);

bool pesquisarBomDia(const std::vector<BomDia> &vBD);
bool pesquisarBomDia(const std::vector<BomDia> &vBD, std::string termoPesquisar);
//const bool pesquisarBomDia(const std::vector<BomDia> &vBD, std::string dataPesquisar);
//const bool pesquisarBomDia(const std::vector<BomDia> &vBD, std::string autorPesquisar);

void deletarBomDia(std::vector<BomDia> &vBD);


void sair(const std::vector<BomDia> &vBD);

#endif // !FUNCOES_H