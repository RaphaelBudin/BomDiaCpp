#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include "BomDia.h"

void clear_screen(void);
void converterMaiuscula(std::string& texto);
void converterMaiuscula(char& letra);

void carregarArquivo(std::vector<BomDia> &vBD);
void salvarArquivo(const std::vector<BomDia> &vBD);
int menuRetornaOpcao();

void addBomDia(std::vector<BomDia> &vBD);

const void mostrarVetorBomDias(const std::vector<BomDia> &vBD);
const void mostrarBomDia(std::vector<BomDia> &vBD, const int posicaoVetor);
const std::string retornarBomDia(std::vector<BomDia> &vBD, const int posicaoVetor);

bool pesquisarBomDia(std::vector<BomDia> &vBD);

bool deletarBomDia(std::vector<BomDia> &vBD, int posicao);
bool deletarBomDia(std::vector<BomDia> &vBD);

void teste(std::vector<BomDia> &vBD);

void sair(const std::vector<BomDia> &vBD);

#endif // !FUNCOES_H