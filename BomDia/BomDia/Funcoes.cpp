#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <fstream>
#include "BomDia.h"
#include <vector>
#include <limits.h>
#include <windows.h>

//A diretiva de pré-processamento #define não tem escopo local definido por {}
//Ela irá substituir toda ocorrência de texto a partir do local que ela foi declarado para baixo no código
//Havia criado uma #define dentro void mostrarBomDia(), e quando tentei declarar uma variável auto p no bool pesquisarBomDia() ele deu erro

//Função perigosa, pelo uso de system
void clear_screen(void) {
// Todas as formas listadas nesta função funcionaram no WINDOWS

//#ifdef _WIN32
//#define CLEAR "cls"
//#else
//#define CLEAR "clear"
//#endif // _WIN32
//	std::system(CLEAR);

	std::system("cls || clear");
}



//
//			Função segura para limpar a tela
//
//#include <windows.h>
//void cls(HANDLE hConsole)
//{
//	COORD coordScreen = { 0, 0 };    // home for the cursor 
//	DWORD cCharsWritten;
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	DWORD dwConSize;
//
//	// Get the number of character cells in the current buffer. 
//
//	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
//	{
//		return;
//	}
//
//	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
//
//	// Fill the entire screen with blanks.
//
//	if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer 
//		(TCHAR)' ',     // Character to write to the buffer
//		dwConSize,       // Number of cells to write 
//		coordScreen,     // Coordinates of first cell 
//		&cCharsWritten))// Receive number of characters written
//	{
//		return;
//	}
//
//	// Get the current text attribute.
//
//	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
//	{
//		return;
//	}
//
//	// Set the buffer's attributes accordingly.
//
//	if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer 
//		csbi.wAttributes, // Character attributes to use
//		dwConSize,        // Number of cells to set attribute 
//		coordScreen,      // Coordinates of first cell 
//		&cCharsWritten)) // Receive number of characters written
//	{
//		return;
//	}
//
//	// Put the cursor at its home coordinates.
//
//	SetConsoleCursorPosition(hConsole, coordScreen);
//}



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

void salvarArquivo(const std::vector<BomDia> &vBD) {
	std::ofstream fout	("arquivoBomDias.txt");
	for (auto p : vBD) {
		int i = 1, tamanhovBD = vBD.size();
		fout << p.getData() + ',' + p.getAutor() + ',' + p.getMensagem();

		//A adição de uma linha vazia causa exibição incorreta de ' // ,  , ' como último registro de bom dia 
		//Durante os testes fout.close() não impediu que novas adições fossem feitas no arquivo
		//Portanto é necessário manter uma estrutura de controle para impedir de adicionar '\n' depois do último registro
		//Dá menos trabalho de manter fazer o registro salvar corretamente do que verificar se a linha está vazia
		if ( i ==  tamanhovBD)
			fout.close();
		else fout << '\n';
		++i;
	}
	std::cout <<"\nArquivo Salvo!\n";
}


int menuRetornaOpcao() {
	std::cout << "Menu: \n";
	std::cout << "0. Limpar tela...\n";
	std::cout << "1. Adicionar bom dia\n";
	std::cout << "2. Mostrar todas as mensagens\n";
	std::cout << "3. Pesquisar Bom Dia\n";
	std::cout << "4. Deletar Bom Dia\n";
	std::cout << "8. Salvar\n";
	std::cout << "9. Sair\n";

	int opcao = -1;
	do {
		std::cout << "Opcao:  ";
		std::cin >> opcao;
	} while (!(opcao >= 0 && opcao <= 9));
	std::cout << "\n";
	return opcao;
}


void addBomDia(std::vector<BomDia> &vBD) {

	//Para limpar o '\n' e não dar BO com nenhum getline 
	//Testes mostraram que é necessário apenas esse 'cin.ignore()' no início para não haver problemas com o getline
	std::cin.ignore();

	std::cout << "Insira o bom dia: ";
	std::string mensagem;
	std::getline(std::cin, mensagem);

	std::cout <<"Insira o autor: ";
	std::string autor;
	std::getline(std::cin, autor);

	std::cout <<"Insira a data no formato dd/mm/aaaa: ";
	std::string tempData;
	std::getline(std::cin, tempData);

	//Converter data em dia, mes, ano
	std::string dia;
	std::string mes;
	std::string ano;
	
	std::istringstream iss(tempData);
	std::getline(iss, dia, '/');
	std::getline(iss, mes, '/');
	std::getline(iss, ano);

	//Parêntesis para deixar todos os nomes dos autores alinhados ao exibir
	BomDia temp(dia, mes, ano, (" " + autor), mensagem);

	vBD.push_back(temp);
}

const void mostrarVetorBomDias(const std::vector<BomDia> &vBD){
	for (auto p : vBD){
		if (p.getData().substr(0, 2) == "//")
			continue;
		else
			std::cout << p.getData() << ", " << p.getAutor() << ", " <<p.getMensagem() <<"\n";
	}
}

//Implementar forma de usar o vBD como 'const', como desafio de otimização do programa
const void mostrarBomDia(std::vector<BomDia> &vBD, const int posicaoVetor) {
	std::cout << vBD.at(posicaoVetor).getData() << ", " << vBD.at(posicaoVetor).getAutor() <<", " << vBD.at(posicaoVetor).getMensagem() <<"\n";
}

const std::string retornarBomDia(std::vector<BomDia>& vBD, const int posicaoVetor) {
	return vBD.at(posicaoVetor).getMensagem();
}

//Implementar forma de usar o vBD como 'const', como desafio de otimização do programa
const std::string retornarLinha(std::vector<BomDia> &vBD, const int posicaoVetor){
	return { vBD.at(posicaoVetor).getData() + ", " + vBD.at(posicaoVetor).getAutor() + ", " + vBD.at(posicaoVetor).getMensagem()};
}

int acharPosicao(std::vector<BomDia>& vBD, short int opcao, std::string dados) {
	int i = 0;
	switch (opcao)
	{
	case 1: //Por Texto 
		for (auto p : vBD) {
			if (p.getMensagem() == dados)
				return i;
			++i;
		}
		break;

	case 2:	//Por Data
		for (auto p : vBD) {
			if (p.getData() == dados)
				return i;
			++i;
		}
		break;

	case 3:	//Por autor
		for (auto p : vBD) {
			if (p.getAutor() == dados)
				return i;
			++i;
		}
		break;

	default:	break;
	}

	return -1;
}


//Implementar forma de usar o vBD como 'const', como desafio de otimização do programa
bool pesquisarBomDia(std::vector<BomDia> &vBD){
	std::cout <<"Selecione o metodo de pesquisa: \n"
				<<"1. Texto\n"
				<<"2. Data\n"
				<<"3. Autor\n"
				<<"---> :";

	//Compilador não deixou inicializar variável abaxio dentro de dos 'case'
	//Informa erro "Desvio de controle da inicialização de variável"
	std::string dados;
	bool achados = 0;
	int i = 0;	//Serve para pegar a opção do usuário  && guardar a posição do vetor
	std::cin >> i;
	switch (i)
	{
	case 1:
		i = 0;
		std::cin.ignore();
		std::cout <<"Insira o termo a ser pesquisado: ";
		std::getline(std::cin, dados);
		for (auto p : vBD){

			//size_t representa um tamanho em bytes ou algum índice, ao invés de apenas outro inteiro qualquer
			//size_t deve ser para especificar o tamanho ou índice de algo
			//size_t é o resultado do operador sizeof
			//size_t ajuda a portabilidade do código
			//Função find retorna um size_t com a posição da substring pesquisada
			std::size_t temp = p.getMensagem().find(dados);	
			//npos é um atributo de strings utilizado em conjunto com size_t
			//Seu valor é -1, sendo o maior valor possível para um unsigned size_t
			//Isso significa que o npos representa o final da string, parecido com o 'vector'.end()
			//Logo, quando algum método retorna npos, significa que cheguou no fim da string sem correspondência
			if (temp!=std::string::npos){
				std::cout << "\n";
				mostrarBomDia(vBD, i);
				++achados;
			}
			++i;
		}
		break;

	case 2:
		i = 0;
		std::cin.ignore();
		std::cout << "Insira a data a ser pesquisada: ";
		std::getline(std::cin, dados);
		for (auto p : vBD) {
			if (p.getData() == dados) {
				mostrarBomDia(vBD, i);
				++achados;
			}
			++i;
		}

	case 3:
		i = 0;
		std::cin.ignore();
		std::cout << "Insira o autor(a) a ser pesquisado(a): ";
		std::getline(std::cin, dados);
		for (auto p : vBD) {
			if (p.getAutor() == dados) {
				mostrarBomDia(vBD, i);
				++achados;
			}
			++i;
		}
	
	default:
		std::cout << "Opcao inserida nao e valida.\nEncerrando funcao...\n";
		break;
	}
	
	if (achados == 0) {
		std::cout << "Nao foi encontrado nada correspondente no vetor... Voce digitou corretamente?\n";
		return false;
	}
	return true;	
}

//bool pesquisarBomDia(const std::vector<BomDia> &vBD, std::string termoPesquisar){
//	return 0;
//}
//
//bool pesquisarBomDia(const std::vector<BomDia> &vBD, std::string dataPesquisar){
//	return 0;
//}
//
//bool pesquisarBomDia(const std::vector<BomDia> &vBD, std::string autorPesquisar){
//	return 0;
//}
//
//void deletarBomDia(std::vector<BomDia> &vBD){
//
//}



void sair(const std::vector<BomDia>  &vBD){
	std::cout <<"Deseja salvar antes de sair? S/N: ";
	std::cin.ignore();	//Limpa o buffer do cin, que está com sujeira de algum cin anterior
	std::string resposta;
	std::cin >> resposta;
	
	//Função std::toupper é barrada pelos avisos do VS
	for (unsigned int i = 0; i < resposta.size(); ++i)
		if (resposta.at(i) >= 'a' && resposta.at(i) <= 'z')
			resposta.at(i) = (resposta.at(i) - ' ');

	//if (resposta == 'S' || resposta == 's')
	if (resposta == "S" || resposta == "SI" || resposta == "SIM")
		salvarArquivo(vBD);
}
