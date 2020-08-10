#ifndef DATA_H
#define DATA_H

class Data {
private:
    unsigned short day;
    unsigned short month;
    unsigned short year; 
public:
    Data(unsigned short consDay, unsigned short consMonth, unsigned short consYear);
    ~Data();

    bool date_is_valid(unsigned short day, unsigned short month, unsigned short year);
};

#endif // !DATA_H