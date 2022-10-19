//
// Created by wen on 2022/10/19.
//

#ifndef C_SCREEN_H
#define C_SCREEN_H
#include <string>
#include <iostream>

class Screen {
public:
    using pos = std::string::size_type;
    Screen()=default;
    Screen(pos w, pos h, char s):width(w),height(h),contents(w*h, s){};
    char get() const {
        return contents[cursor];
    }
    inline char get(pos w, pos h) const;
    Screen& move(pos w ,pos h);
    Screen& set(char);
    Screen& set(pos,pos,char);
    Screen& display(std::ostream& os) {
        do_display(os);
        return *this;
    }
private:

    pos cursor=0;
    pos width=0,height=0;
    std::string contents;
    mutable int access_ctr;
    void do_display(std::ostream& os) const{
        os << contents;
    }
};


#endif //C_SCREEN_H
