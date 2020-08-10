#ifndef BOMDIA
#define BOMDIA

#include <iostream>
#include <string>
#include <vector>

class BomDia
{
private:
	std::string author;
	std::string message;
	std::string day;
	std::string month;
	std::string year;

public:
	BomDia();
	BomDia(unsigned short day, unsigned short month, unsigned short year, std::string author, std::string message);

	const std::string get_author();
	void set_author(std::string new_author);
	
	const std::string get_message();
	void set_message(std::string new_message);
	
	const std::string get_date();
	bool set_date(unsigned short new_day, unsigned short new_month, unsigned short new_year);
	
};

#endif