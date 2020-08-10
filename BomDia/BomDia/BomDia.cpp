#include <iostream>
#include <string>
#include <vector>
#include "BomDia.h"

BomDia::BomDia(){
	this->author = "";
	this->message = "";
	this->day = "";
	this->month = "";
	this->year = "";
}

//o "c" no nome das variáveis significa "construtor", para diferenciar do atributo final
BomDia::BomDia(unsigned short c_day, unsigned short c_month, unsigned short c_year, std::string c_author, std::string c_message) {
	this->set_date(c_day, c_month, c_year);
	this->author = c_author;
	this->message = c_message;
	// this->day = c_day;
	// this->month = c_month;
	// this->year = c_year;
}

const std::string BomDia::get_author() 														{
	return this->author;																		}

void BomDia::set_author(std::string new_author) 												{
	this->author = new_author;																}

const std::string BomDia::get_message() 													{
	return this->message;																	}

void BomDia::set_message(std::string novaMensagem) 											{
	this->message = novaMensagem;															}

const std::string BomDia::get_date() 														{
	return { this-> day + '/' + this->month + '/' + this->year };								}



bool BomDia::set_date(unsigned short day, unsigned short month, unsigned short year) {
	//Validar mês
	if (month < 1 || month > 12){
		std::cout <<"Mes " <<month <<" inserido invalido. Insira entre 1 e 12.\n";
		return 0;
	}

	//Calcular se um year é bissexto a fim de validar os dias de fevereiro
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
		//Fevereiro - Validar dias
		if (month == 2 && (day < 1 || day > 29)){
			std::cout <<"Dia " <<day <<" inserido invalido. Insira entre 1 e 29.\n";
			return 0;
		}
		if (day < 1 || day > 28){
			std::cout <<"Dia " <<day <<" inserido invalido. Insira entre 1 e 28.\n";
			return 0;
		}
	}

	//Checa se o day inserido é inválido para os meses com 30 dias
	else if (month == 4 || month == 6 || month == 9 || month == 11 && (day < 1 || day > 30)){
		std::cout <<"Dia " <<day <<" inserido invalido. Insira entre 1 e 30.\n";
		return 0;
	}

	//Checa se o day inserido é inválido para os meses com 31 dias
	else if (month != 4 && month != 6 && month != 9 && month != 11 && (day < 1 || day > 31)){
		std::cout <<"Dia " <<day <<" inserido invalido. Insira entre 1 e 31.\n";
		return 0;
	}

	//Tudo certo
	else {
		//Otimizar o código posteriormente fazendo day, month e year serem short int ao invés de strings
		this->day = day;
		this->month = month;
		this->year = year;		
	}
	return 1;
}