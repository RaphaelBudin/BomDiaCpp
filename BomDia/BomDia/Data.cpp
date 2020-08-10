#include "Data.h"
#include <iostream>

Data::Data(unsigned short consDay, unsigned short consMonth, unsigned short consYear){
	if (this->date_is_valid(consDay, consMonth, consYear)){
		this->day = consDay;
		this->month = consMonth;
		this->year = consYear;
	}
	else
		std::cout <<"Excluindo construtor...\n";
	
}

Data::~Data(){}

bool Data::date_is_valid(unsigned short day, unsigned short month, unsigned short year){
	
	if (month < 1 || month > 12){
		std::cout <<"Mes inserido invalido. Insira entre 1 e 12.\n";
		return 0;	}

	//Bissexo - (validar fevereiro mais pra frente)
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
		if (month == 2 && (day < 1 || day > 29)){
			std::cout <<"Dia inserido invalido. Insira entre 1 e 29.\n";
			return 0;		}
		if (day < 1 || day > 28){
			std::cout <<"Dia inserido invalido. Insira entre 1 e 28.\n";
			return 0;		}
	}
	//Checa se o dia inserido é inválido para os meses com 30 dias
	if (month == 4 || month == 6 || month == 9 || month == 11 && (day < 1 || day > 30)){
		std::cout <<"Dia inserido invalido. Insira entre 1 e 30.\n";
		return 0;	
	}

	//Checa se o dia inserido é inválido para os meses com 31 dias
	else if (month != 4 && month != 6 && month != 9 && month != 11 && (day < 1 || day > 31)){
		std::cout <<"Dia inserido invalido. Insira entre 1 e 31.\n";
		return 0;	
	}
	return 1;
}