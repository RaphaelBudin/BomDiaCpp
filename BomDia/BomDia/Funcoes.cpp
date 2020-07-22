#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <fstream>
#include "BomDia.h"
#include <vector>
#include <limits.h>

void carregarArquivo(std::vector<BomDia> &vBD) {
	std::ifstream fin("arquivoBomDias.txt");
	if (!fin) {
		std::cout << "ERRO ao abrir arquivo. Saindo do programa...\n";
		exit(1);
	}

	while (!fin.eof()) {
		std::string linha;
		std::getline(fin, linha);
		std::istringstream iss(linha);

		std::string data;
		std::getline(iss, data, ',');
		std::istringstream issData(data);
		//Dia, mes e ano são tratados como string por conta do getline abaixo, pois não aceita (istringstream, int, char) apenas (istringstream, string, char)
		//Depois basta fazer o explicit casting e tudo resolvido
		std::string dia, mes, ano;
		std::getline(issData, dia, '/');
		std::getline(issData, mes, '/');
		std::getline(issData, ano);

		std::string autor;
		std::getline(iss, autor, ',');

		std::string mensagem;
		std::getline(iss, mensagem);

		BomDia temp(dia, mes, ano, autor, mensagem);

		vBD.push_back(temp);
	}
	fin.close();
}

void salvarArquivo(std::vector<BomDia> const &vBD) {
	std::ofstream fout	("arquivoBomDias.txt");
	for (auto p : vBD) {
		int i = 1, tamanhovBD = vBD.size();
		fout << p.getData() + ',' + p.getAutor() + ',' + p.getMensagem();
		if ( i ==  tamanhovBD) {
			fout.close();
		}
		fout << '\n';
		++i;
	}
	std::cout <<"\nArquivo Salvo!\n";
}


int menuRetornaOpcao() {
	std::cout << "Menu: \n";
	std::cout << "1. Adicionar bom dia\n";
	std::cout << "2. Mostrar todas as mensagens\n";
	std::cout << "3. Pesquisar Bom Dia\n";
	std::cout << "4. Deletar Bom Dia\n";
	std::cout << "8. Salvar\n";
	std::cout << "9. Sair\n";

	int opcao = -1;
	do {
		std::cin >> opcao;
	} while (!(opcao > 0 && opcao < 10));

	return opcao;
}

void addBomDia() {
	std::cout << "Insira o bom dia: ";
	std::string bomDia;
	std::cin >> bomDia;

}

// void mostrarBomDias(BomDia const &vBD){

// }



void sair(std::vector<BomDia> const &vBD){
	std::cout <<"Deseja salvar antes de sair? S/N: ";
	std::cin.ignore();	//Limpa o buffer do cin, que está com sujeira de algum cin anterior
	char resposta;
	std::cin.get(resposta);
	if (resposta == 'S' || resposta == 's')
		salvarArquivo(vBD);
}
