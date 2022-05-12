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
    
    string filename;
    filename.append(getlogin());
    filename.append(".log");
    cout << "error" << endl;
    
    path += "/";
    path += filename;
    return CCConfig{ path, "cc" };
}
