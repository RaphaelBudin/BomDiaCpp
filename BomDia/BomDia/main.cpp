#include <iostream>
#include "Funcoes.h"
#include "BomDia.h"
//montar e criar arquvios dos bom dias

//não usar namespace global. Evitar usar ao todo. No máximo usar dentro de um escopo definido

int main()
{
    std::vector<BomDia> vBD{};
    carregarArquivo(vBD);
    salvarArquivo(vBD);
    
    std::cout << "BOM DIA BB!\n";
    while (1) {
        switch (menuRetornaOpcao()) {
        case 1: addBomDia();
            break;
        case 2: salvarArquivo(vBD);
            break;
        default: 
            break;
        }
    }

    //Carregar bom dia de todas as pessoas na memória
    //Menu Principal
        //Selecionar opção
        //Adicionar Bom Dia
        //Adicionar Pessoa
        //Mostrar Todos os bom dias por pessoa
        //Mostrar Todos os bom dias por data
        //Pesquisar Bom Dia por string
        //Pesquisar Bom Dia por data
        //Ordenar vetor
        //Sair
}
