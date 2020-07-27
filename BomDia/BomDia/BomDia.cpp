#include <iostream>
#include <string>
#include <vector>
#include "BomDia.h"

BomDia::BomDia(){
	this->autor = "";
	this->mensagem = "";
	this->dia = "";
	this->mes = "";
	this->ano = "";
}

//o "c" no nome das variáveis significa "construtor", para diferenciar do atributo final
BomDia::BomDia(std::string cdia, std::string cmes, std::string cano, std::string cautor, std::string cmensagem) {
	this->autor = cautor;
	this->mensagem = cmensagem;
	this->dia = cdia;
	this->mes = cmes;
	this->ano = cano;
}

const std::string BomDia::getAutor() 									{
	return this->autor;											}

void BomDia::setAutor(std::string novoAutor) 					{
	this->autor = novoAutor;									}

const std::string BomDia::getMensagem() 								{
	return this->mensagem;										}

void BomDia::setMensagem(std::string novaMensagem) 				{
	this->mensagem = novaMensagem;								}

const std::string BomDia::getData() 									{
	return { this->dia + '/' + this->mes + '/' + this->ano };	}



bool BomDia::setData(std::string nDia, std::string nMes, std::string nAno) {
	//Já tinha feito a validação em formato de int
	//Fica mais fácil fazer como int ao invés de string
	//Manter dessa forma, a menos que os atributos dia,mes,ano voltem a serem int
	//
	//Compilador acusava erro de conversão de 'int' para 'const_Elem' -> possível perda de dados
	//
	const int novoDia = std::stoi(nDia);
	const int novoMes = std::stoi(nMes);
	const int novoAno = std::stoi(nAno);

	//Validar mês
	if (novoMes < 1 || novoMes > 12){
		std::cout <<"Mes inserido invalido. Insira entre 1 e 12.\n";
		return 1;
	}

	//Calcular se um ano é bissexto a fim de validar os dias de fevereiro
	if (novoAno % 400 == 0 || (novoAno % 4 == 0 && novoAno % 100 != 0)){
		//Fevereiro - Validar dias
		if (novoMes == 2 && (novoDia < 1 || novoDia > 29)){
			std::cout <<"Dia inserido invalido. Insira entre 1 e 29.\n";
			return 1;
		}
		if (novoDia < 1 || novoDia > 28){
			std::cout <<"Dia inserido invalido. Insira entre 1 e 28.\n";
			return 1;
		}
	}

	//Checa se o dia inserido é inválido para os meses com 30 dias
	else if (novoMes == 4 || novoMes == 6 || novoMes == 9 || novoMes == 11 && (novoDia < 1 || novoDia > 30)){
		std::cout <<"Dia inserido invalido. Insira entre 1 e 30.\n";
		return 1;
	}

	//Checa se o dia inserido é inválido para os meses com 31 dias
	else if (novoMes != 4 && novoMes != 6 && novoMes != 9 && novoMes != 11 && (novoDia < 1 || novoDia > 31)){
		std::cout <<"Dia inserido invalido. Insira entre 1 e 31.\n";
		return 1;
	}

	//Tudo certo
	else {
		this->dia = novoDia;
		this->mes = novoMes;
		this->ano = novoAno;		
	}
	return 0;
}