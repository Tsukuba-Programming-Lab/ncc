//
//  CCConfigFactory.cpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#include <iostream>
#include "CCConfigFactory.hpp"

string get_username() {
    auto username = getenv("LOGNAME");
    if (username == NULL) {
        throw "User名が取得できませんでした。"s;
    } else {
        return string(username);
    }
}

auto CCConfigFactory::make_debug(string logfile) -> CCConfig {
    return CCConfig{ logfile, "gcc" };
}
auto CCConfigFactory::make_user(string basepath) -> CCConfig {
    auto path = basepath;
    string filename = get_username() + ".log";
    path += "/";
    path += filename;
    return CCConfig{ path, "cc" };
}

