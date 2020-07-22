#pragma once
#include <iostream>
#include <string>
#include <vector>

class BomDia
{
private:
	std::string autor;
	std::string mensagem;
	std::string dia;
	std::string mes;
	std::string ano;

public:
	BomDia(std::string dia, std::string mes, std::string ano, std::string autor, std::string mensagem);

	std::string getAutor();
	void setAutor(std::string novoAutor);
	
	std::string getMensagem();
	void setMensagem(std::string novaMensagem);
	
	std::string getData();
	void setData(int novoDia, int novoMes, int novoAno);
	
};
