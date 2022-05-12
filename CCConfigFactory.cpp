//
//  CCConfigFactory.cpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#include <iostream>
#include "CCConfigFactory.hpp"

auto CCConfigFactory::make_debug(string logfile) -> CCConfig {
    return CCConfig{ logfile, "gcc" };
}
auto CCConfigFactory::make_user(string basepath) -> CCConfig {
    auto path = basepath;
    cout << "error1" << endl;
    auto filename = string(getlogin()) + ".log";
    cout << "error2" << endl;
    path += "/";
    path += filename;
    cout << "error3" << endl;
    return CCConfig{ path, "cc" };
}
