#pragma once
#include <iostream>
#include <string>
#include <vector>

class BomDia
{
private:
	int ID;
	std::string pessoa;
	std::string bomDia;
	std::string data;

public:
	int getID();
	void setID(int ID);
	std::string getPessoa();
	std::string getBomDia();
	std::string getData();
	
};

