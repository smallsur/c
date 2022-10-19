//
// Created by wen on 2022/10/19.
//

#ifndef C_WINDOW_MGR_H
#define C_WINDOW_MGR_H

#include<vector>
#include "Screen.h"

class Window_mgr {
private:
    std::vector<Screen> screens{Screen(24,80,' ')};
};


#endif //C_WINDOW_MGR_H
