#include <iostream>
#include "Funcoes.h"
#include "BomDia.h"
//montar e criar arquvios dos bom dias

//não usar namespace global. Evitar usar ao todo. No máximo usar dentro de um escopo definido

int main()
{
    std::vector<BomDia> vBD{};
    carregarArquivo(vBD);
    std::cout << "BOM DIA BB!\n";
    int on = true;
    while (on) {
        switch (menuRetornaOpcao()) {

        case 1: addBomDia();
            break;
        case 2: mostrarBomDias(vBD);
            break;
        case 3: pesquisarBomDia(vBD);
            break;
        case 4: deletarBomDia(vBD);
            break;
        case 8: salvarArquivo(vBD);
            break;
        case 9: sair(vBD);
            on = false;
            break;
        default: 
            break;
        }
    }
    std::cout <<"Saindo do programa... \n\n";

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