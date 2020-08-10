#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include "BomDia.h"

void clear_screen(void);
void convert_To_Upper(std::string& text);
void convert_To_Upper(char& letter);

void loadArchive(std::vector<BomDia> &vBD);
void saveArchive(const std::vector<BomDia> &vBD);
int menuReturnOption();

void addBomDia(std::vector<BomDia> &vBD);

const void showVectorBomDias(const std::vector<BomDia> &vBD);
const void showBomDias(std::vector<BomDia> &vBD, const int positionVector);
const std::string returnBomDias(std::vector<BomDia> &vBD, const int positionVector);

const std::string returnLine(std::vector<BomDia> &vBD, const int positionVector);
int findPosition(std::vector<BomDia>& vBD, short int option, std::string data);
bool searchBomDia(std::vector<BomDia> &vBD);

bool deleteBomDia(std::vector<BomDia> &vBD, int position);
bool deleteBomDia(std::vector<BomDia> &vBD);

void exit(const std::vector<BomDia> &vBD);

#endif // !FUNCOES_H