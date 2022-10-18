//
// Created by wen on 2022/10/14.
//

#ifndef C_SALES_DATA_H
#define C_SALES_DATA_H

#include <string>
#include <iostream>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data() = default;
    Sales_data(const std::string& s):bookNo(s){};
    Sales_data(const std::string& s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p){};
    Sales_data(std::istream&);

    std::string isbn() const {return this->bookNo;}

    Sales_data& combine(const Sales_data&);

    double avg_price() const;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);


#endif //C_SALES_DATA_H
