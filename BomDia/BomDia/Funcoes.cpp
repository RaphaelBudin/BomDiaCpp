#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <fstream>
#include "BomDia.h"
#include <vector>
#include <limits.h>
#include <assert.h>
#include <ctype.h>

#if __WIN32
	#include <windows.h>
#endif


//A diretiva de pré-processamento #define não tem escopo local definido por {}
//Ela irá substituir toda ocorrência de text a partir do local que ela foi declarado para baixo no código
//Havia criado uma #define dentro void showBomDias(), e quando tentei declarar uma variável auto p no bool searchBomDia() ele deu erro

//Função perigosa, pelo uso de system
void clear_screen(void) {
	std::system("cls || clear");
}


void convert_To_Upper(std::string& text) {
	for (unsigned int i = 0; i < text.size(); ++i)
		if (text.at(i) >= 'a' && text.at(i) <= 'z')
			text.at(i) = (text.at(i) - ' ');
}

void convert_To_Upper(char& letter) {
	if (letter >= 'a' && letter <= 'z')	
		letter = (letter - ' ');
}


void loadArchive(std::vector<BomDia> &vBD) {
	std::ifstream fin("arquivoBomDias.txt");
	if (!fin) {
		std::cout << "ERRO ao abrir arquivo. Saindo do programa...\n";
		exit(1);
	}

	while (!fin.eof()) {
		std::string line;
		std::getline(fin, line);
		std::istringstream iss(line);

		std::string date;
		std::getline(iss, date, ',');
		//Filtra inserções vazias no vetor
		if (date.substr(0, 2) == "//")		continue;
		std::istringstream issDate(date);
		//Dia, month e year são tratados como string por conta do getline abaixo, pois não aceita (istringstream, int, char) apenas (istringstream, string, char)
		//Depois basta fazer o explicit casting ou stoi
		std::string day, month, year;
		std::getline(issDate, day, '/');
		std::getline(issDate, month, '/');
		std::getline(issDate, year);
		unsigned short iday = std::stoi(day);
		unsigned short imonth = std::stoi(month);
		unsigned short iyear = std::stoi(year);

		std::string author;
		std::getline(iss, author, ',');

		std::string message;
		std::getline(iss, message);

		convert_To_Upper(author);
		convert_To_Upper(message);

		//Parêntesis para deixar todos os nomes dos autores alinedos ao exibir
		BomDia temp(iday, imonth, iyear, (" " + author), message);

		vBD.push_back(temp);
	}
	fin.close();
}

void saveArchive(const std::vector<BomDia> &vBD) {
	std::ofstream fout	("arquivoBomDias.txt");
	for (auto p : vBD) {
		//Ignora Bom Dias vazios
		if (p.get_date().substr(0, 2) == "//")
			continue;
		int i = 1, sizevBD = vBD.size();
		fout << p.get_date() + ',' + p.get_author() + ',' + p.get_message();

		//A adição de uma line vazia causa exibição incorreta de ' // ,  , ' como último registro de bom day 
		//Durante os testes fout.close() não impediu que novas adições fossem feitas no arquivo
		//Portanto é necessário manter uma estrutura de controle para impedir de adicionar '\n' depois do último registro
		//Dá menos trabalho de manter fazer o registro salvar corretamente do que verificar se a line está vazia (foi implementado mesmo assim)
		
		if (i == sizevBD) {
			fout.close();
			break;
		}
		else fout << '\n';
		++i;
	}
	std::cout <<"\nArquivo Salvo!\n";
}


int menuReturnOption() {
	std::cout << "Menu: \n";
	std::cout << "0. Limpar tela...\n";
	std::cout << "1. Adicionar bom day\n";
	std::cout << "2. Mostrar todas as mensagens\n";
	std::cout << "3. Pesquisar Bom Dia\n";
	std::cout << "4. Deletar Bom Dia\n";
	std::cout << "8. Salvar\n";
	std::cout << "9. exit\n";

	int option = -1;
	do {
		std::cout << "Opcao:  ";
		std::cin >> option;
		if (!isdigit(option) || std::cin.fail()){
			std::cout <<"Insira apenas numbers!\n";
			option = -1;
		}
	} while (!(option >= 0 && option <= 9));
	std::cout << "\n";
	return option;
}


void addBomDia(std::vector<BomDia> &vBD) {

	//Para limpar o '\n' e não dar BO com nenhum getline 
	//Testes mostraram que é necessário apenas esse 'cin.ignore()' no início para não haver problemas com o getline
	std::cin.ignore();

	std::cout << "Insira o bom day: ";
	std::string message;
	std::getline(std::cin, message);

	std::cout <<"Insira o autor: ";
	std::string author;
	std::getline(std::cin, author);

	std::cout <<"Insira a data no formato dd/mm/aaaa: ";
	std::string tempDate;
	std::getline(std::cin, tempDate);
	std::string day, month, year;
	std::istringstream iss(tempDate);
	std::getline(iss, day, '/');
	std::getline(iss, month, '/');
	std::getline(iss, year);

	unsigned short iday = std::stoi(day);
	unsigned short imonth = std::stoi(month);
	unsigned short iyear = std::stoi(year);

	//Parêntesis para deixar todos os nomes dos autores alinedos ao exibir
	BomDia temp(iday, imonth, iyear, (" " + author), message);
	vBD.push_back(temp);
}

const void showVectorBomDias(const std::vector<BomDia> &vBD){
	int i = 0;
	for (auto p : vBD){
		if (p.get_date().substr(0, 2) == "//")
			continue;
		else
			std::cout <<"number : " <<i++ <<" - " <<p.get_date() << ", " << p.get_author() << ", " <<p.get_message() <<"\n";
	}
}

//Implementar forma de usar o vBD como 'const', como desafio de otimização do programa
const void showBomDias(std::vector<BomDia> &vBD, const int positionVector) {
	std::cout <<"Posicao no Vetor: " <<positionVector <<" - " <<vBD.at(positionVector).get_date() << ", " << vBD.at(positionVector).get_author() <<", " << vBD.at(positionVector).get_message() <<"\n";
}

const std::string returnBomDias(std::vector<BomDia>& vBD, const int positionVector) {
	return vBD.at(positionVector).get_message();
}

//Implementar forma de usar o vBD como 'const', como desafio de otimização/documentação do programa
const std::string returnLine(std::vector<BomDia> &vBD, const int positionVector){
	return { vBD.at(positionVector).get_date() + ", " + vBD.at(positionVector).get_author() + ", " + vBD.at(positionVector).get_message()};
}

int findPosition(std::vector<BomDia>& vBD, short int option, std::string data) {
	int i = 0;
	convert_To_Upper(data);
	switch (option)
	{
	case 1: //Por Texto 
		for (auto p : vBD) {
			std::size_t temp = p.get_message().find(data);
			if (temp != std::string::npos)
				return i;
			++i;
		}
		break;

	case 2:	//Por Data
		for (auto p : vBD) {
			std::size_t temp = p.get_date().find(data);
			if (temp != std::string::npos)
				return i;
			++i;
		}
		break;

	case 3:	//Por autor
		for (auto p : vBD) {
			std::size_t temp = p.get_author().find(data);
			if (temp != std::string::npos)
				return i;
			++i;
		}
		break;
	default:	break;
	}
	return -1;
}


//Implementar forma de usar o vBD como 'const', como desafio de otimização do programa
bool searchBomDia(std::vector<BomDia> &vBD){
	std::cout <<"Selecione o metodo de pesquisa: \n"
				<<"1. Texto\n"
				<<"2. Data\n"
				<<"3. Autor\n"
				<<"---> :";

	//Compilador não deixou inicializar variável abaxio dentro de dos 'case'
	//Informa erro "Desvio de controle da inicialização de variável"
	std::string data;
	bool found = 0;
	int i = 0;	//Serve para pegar a opção do usuário  && guardar a posição do vetor
	std::cin >> i;
	switch (i)
	{
	case 1:
		i = 0;
		std::cin.ignore();
		std::cout <<"Insira o termo a ser pesquisado: ";
		std::getline(std::cin, data);
		convert_To_Upper(data);
		for (auto p : vBD){	
			std::size_t temp = p.get_message().find(data);	
			if (temp!=std::string::npos){
				std::cout << "\n";
				showBomDias(vBD, i);
				found = true;
			}
			++i;
		}
		break;

	case 2:
		i = 0;
		std::cin.ignore();
		std::cout << "Insira a data a ser pesquisada: ";
		std::getline(std::cin, data);
		for (auto p : vBD) {
			std::size_t temp = p.get_date().find(data);
			if (temp != std::string::npos) {
				showBomDias(vBD, i);
				found = true;
			}
			++i;
		}
		break;

	case 3:
		i = 0;
		std::cin.ignore();
		std::cout << "Insira o autor(a) a ser pesquisado(a): ";
		std::getline(std::cin, data);
		convert_To_Upper(data);
		for (auto p : vBD) {
			std::size_t temp = p.get_author().find(data);
			if (temp != std::string::npos) {
				showBomDias(vBD, i);
				found = true;
			}
			++i;
		}
		break;
	default:
		std::cout << "Opcao inserida nao e valida.\nEncerrando funcao...\n";
		break;
	}
	if (found == 0) {
		std::cout << "Nao foi encontrado nada correspondente no vetor... Voce digitou corretamente?\n";
		return false;
	}
	return true;	
}

bool deleteBomDia(std::vector<BomDia> &vBD){
	std::cout <<"Selecione o number do registro a ser deletado: \n";
	showVectorBomDias(vBD);
	unsigned int number = -1;
	std::cin >> number;
	vBD.erase(vBD.begin()+number);
	std::cout <<"Registro deletado com sucesso!\n";
	return true;
}

//Passar índice para deletar automaticamente
bool deleteBomDia(std::vector<BomDia> &vBD, int position){
	if (position < vBD.size() || position >= vBD.size() )	{
		std::cout <<"Valor invalido\n";
		return false;
	}	
	vBD.erase(vBD.begin()+position);
	std::cout <<"Registro deletado\n";
	return true;
}



void exit(const std::vector<BomDia>  &vBD){
	std::cout <<"Deseja salvar antes de sair? S/N: ";
	std::cin.ignore();	//Limpa o buffer do cin, que está com sujeira de algum cin anterior
	std::string answer;
	std::cin >> answer;
	
	//Função std::toupper é barrada pelos avisos do VS
	for (unsigned int i = 0; i < answer.size(); ++i)
		if (answer.at(i) >= 'a' && answer.at(i) <= 'z')
			answer.at(i) = (answer.at(i) - ' ');

	//if (answer == 'S' || answer == 's')
	if (answer == "S" || answer == "SI" || answer == "SIM")
		saveArchive(vBD);
}
