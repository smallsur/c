//
// Created by wen on 2022/10/14.
//

#ifndef C_SALES_DATA_H
#define C_SALES_DATA_H

#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


#endif //C_SALES_DATA_H
