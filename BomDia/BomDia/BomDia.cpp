#include <iostream>
#include <string>
#include <vector>
#include "BomDia.h"

//o "c" no nome das variáveis significa "construtor", para diferenciar do atributo final
BomDia::BomDia(std::string cdia, std::string cmes, std::string cano, std::string cautor, std::string cmensagem) {
	this->autor = cautor;
	this->mensagem = cmensagem;
	this->dia = cdia;
	this->mes = cmes;
	this->ano = cano;
}



std::string BomDia::getAutor() {
	return this->autor;			}

void BomDia::setAutor(std::string novoAutor) {
	this->autor = novoAutor;					}

std::string BomDia::getMensagem() {
	return this->mensagem;			}

void BomDia::setMensagem(std::string novaMensagem) {
	this->mensagem = novaMensagem;					}


std::string BomDia::getData() {
	return { this->dia + '/' + this->mes + '/' + this->ano };		
}

void BomDia::setData(int novoDia, int novoMes, int novoAno) {
	this->dia = novoDia;
	this->mes = novoMes;
	this->ano = novoAno;									
}