//
// Created by wen on 2022/10/14.
//

#include "Sales_data.h"

double Sales_data::avg_price() const {
    if(this->units_sold ==0 ){
        return 0;
    }
    return this->revenue/ this->units_sold;
}

Sales_data &Sales_data::combine(const Sales_data & data_) {
    this->units_sold += data_.units_sold;
    this->revenue += data_.revenue;
    return *this;
}

std::ostream& print(std::ostream& os,const Sales_data& data_){
    os << data_.isbn() << " " << data_.units_sold << " " << data_.revenue
    << " " << data_.avg_price();
    return os;
}

std::istream& read(std::istream& is,Sales_data& data_){
    double price =0.0;
    is >> data_.bookNo >> data_.units_sold >>price;
    data_.revenue = price * data_.units_sold;
    return is;
}

Sales_data add(const Sales_data& data1_, const Sales_data& data2_){
    Sales_data s = data1_;
    s = s.combine(data2_);
    return s;
}

Sales_data::Sales_data(std::istream & is) {
    read(is,*this);
}