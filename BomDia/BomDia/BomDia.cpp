#include <iostream>
#include <string>
#include <vector>
#include "BomDia.h"

int BomDia::getID() {
	return this->ID;
}

void BomDia::setID(int novoID) {
	this->ID = novoID;	}

std::string BomDia::getPessoa() {
	return this->pessoa;	}

std::string BomDia::getBomDia() {
	return this->bomDia;	}

std::string BomDia::getData() {
	return this->data;
}
