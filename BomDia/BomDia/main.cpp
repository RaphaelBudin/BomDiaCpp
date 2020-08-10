#include <iostream>
#include "Funcoes.h"
#include "BomDia.h"
#include <locale.h>  
//montar e criar arquvios dos bom dias

//não usar namespace global. Evitar usar ao todo. No máximo usar dentro de um escopo definido

int main()
{
    setlocale(LC_ALL,"");
    std::vector<BomDia> vBD{};
    loadArchive(vBD);
    std::cout << "BOM DIA BB!\n";
    int on = true;
    while (on) {
        switch (menuReturnOption()) {
        case 0: clear_screen();            break;
        case 1: addBomDia(vBD);            break;
        case 2: showVectorBomDias(vBD);  break;
        case 3: searchBomDia(vBD);      break;
        case 4: deleteBomDia(vBD);        break;
        //case 5: teste(vBD);                break;
        case 8: saveArchive(vBD);        break;
        case 9: exit(vBD);   on = false;   break;
        default:                           break;
        }
        std::cout << "\n";
    }
    std::cout <<"Saindo do programa... \n\n";
}