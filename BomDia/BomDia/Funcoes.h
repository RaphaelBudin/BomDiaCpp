#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include "BomDia.h"

void carregarArquivo(std::vector<BomDia> &vBD);
void salvarArquivo(const std::vector<BomDia> &vBD);
int menuRetornaOpcao();

void addBomDia();

void mostrarVetorBomDias(const std::vector<BomDia> &vBD);
void mostrarBomDia(const std::vector<BomDia> &vBD);
std::string retornarBomDia(std::vector<BomDia> &vBD, const int posicaoVetor);

bool pesquisarBomDia(const std::vector<BomDia> &vBD);
bool pesquisarBomDia(const std::vector<BomDia> &vBD, std::string termoPesquisar);
bool pesquisarBomDia(const std::vector<BomDia> &vBD, std::string dataPesquisar);
bool pesquisarBomDia(const std::vector<BomDia> &vBD, std::string autorPesquisar);

void deletarBomDia(std::vector<BomDia> &vBD);


void sair(const std::vector<BomDia> &vBD);

#endif // !FUNCOES_H