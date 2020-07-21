#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <fstream>
#include "BomDia.h"
#include <vector>

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

		/*int iDia = std::stoi(dia, nullptr, 10);
		int iMes = std::stoi(mes);
		int iAno = std::stoi(ano);*/

		std::string autor;
		std::getline(iss, autor, ',');

		std::string mensagem;
		std::getline(iss, mensagem);

		BomDia temp(std::stoi(dia, nullptr, 10), std::stoi(mes, nullptr, 10), std::stoi(ano, nullptr, 10), autor, mensagem);

		vBD.push_back(temp);
	}
	fin.close();
}

void salvarArquivo(std::vector<BomDia> & vBD) {
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
}


int menuRetornaOpcao() {
	std::cout << "Menu: \n";
	std::cout << "1. Adicionar bom dia\n";
	std::cout << "2. Pesquisar bom dia\n";
	std::cout << "3. Exibir bom dias\n";
	std::cout << "8. Salvar\n";

	int opcao = -1;
	do {
		std::cin >> opcao;
	} while (!(opcao > 0 && opcao < 9));

	return opcao;
}

void addBomDia() {
	std::cout << "Insira o bom dia: ";
	std::string bomDia;
	std::cin >> bomDia;

}