#ifndef BOMDIA
#define BOMDIA

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
	BomDia();
	BomDia(std::string dia, std::string mes, std::string ano, std::string autor, std::string mensagem);

	const std::string getAutor();
	void setAutor(std::string novoAutor);
	
	const std::string getMensagem();
	void setMensagem(std::string novaMensagem);
	
	const std::string getData();
	bool setData(std::string novoDia, std::string novoMes, std::string novoAno);
	
};


#endif