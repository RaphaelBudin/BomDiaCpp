#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <fstream>

void carregarArquivo() {
	std::ifstream fin("arquivoBomDias.txt");
	if (!fin) {
		std::cout << "ERRO ao abrir arquivo. Saindo do programa...\n";
		exit(1);
	}

	 
}
int salvarArquivo() {
	std::ofstream fout	("arquivoBomDias.txt");
	fout << "teste";
	fout.close();

	return 0;
}


int menuRetornaOpcao() {
	std::cout << "Menu: \n";
	std::cout << "1. Adicionar bom dia\n";
	std::cout << "2. Pesquisar bom dia\n";

	int opcao = -1;
	do {
		std::cin >> opcao;
	} while (!(opcao > 0 && opcao < 3));

	return opcao;
}

void addBomDia() {
	std::cout << "Insira o bom dia: ";
	std::string bomDia;
	std::cin >> bomDia;

}