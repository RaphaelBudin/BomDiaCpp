#pragma once
#include <iostream>
#include <string>
#include <vector>

class BomDia
{
private:
	std::string autor;
	std::string mensagem;
	int dia;
	int mes;
	int ano;

public:
	BomDia(int dia, int mes, int ano, std::string autor, std::string mensagem);
	std::string getAutor();
	void setAutor(std::string novoAutor);
	std::string getMensagem();
	void setMensagem(std::string novaMensagem);
	std::string getData();
	void setData(int novoDia, int novoMes, int novoAno);
	
};

