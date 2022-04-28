//
//  CCConfigFactory.cpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#include "CCConfigFactory.hpp"

auto CCConfigFactory::make_debug(string logfile) -> CCConfig {
    return CCConfig{ logfile, "gcc" };
}
auto CCConfigFactory::make_user(filesystem::path const basepath) -> CCConfig {
    auto path = basepath;
    auto username = string(getlogin()) + ".log";
    path.append(username);
    return CCConfig{ path.string(), "cc" };
}
