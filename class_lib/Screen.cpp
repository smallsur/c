//
// Created by wen on 2022/10/19.
//

#include "Screen.h"

inline char Screen::get(pos w, pos h) const {
    ++access_ctr;
    return contents[w*width+h];
}


inline Screen &Screen::move(pos w, pos h) {
    cursor = w*width+h;
    return *this;
}


inline Screen &Screen::set(char c) {
    contents[cursor]=c;
    return *this;
}

inline Screen &Screen::set(pos w, pos h, char c) {
    contents[w*width+h] = c;
    return *this;
}
