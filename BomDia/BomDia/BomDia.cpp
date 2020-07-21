#include <iostream>
#include <string>
#include <vector>
#include "BomDia.h"

BomDia::BomDia(int dia, int mes, int ano, std::string autor, std::string mensagem) {
	this->autor = autor;
	this->mensagem = mensagem;
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
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
	std::string sDia, sMes, sAno;
	sDia = (char*)this->dia;
	sMes = (char*)this->mes;
	sAno = (char*)this->ano;

	return { sDia + '/' + sMes + '/' + sAno };		
}

void BomDia::setData(int novoDia, int novoMes, int novoAno) {
	this->dia = novoDia;
	this->mes = novoMes;
	this->ano = novoAno;									
}