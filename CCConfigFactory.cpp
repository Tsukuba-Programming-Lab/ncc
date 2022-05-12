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
    cout << "error" << endl;
    auto filename = string(getlogin()) + ".log";
    path += "/";
    path += filename;
    cout << "error" << endl;
    return CCConfig{ path, "cc" };
}
