//
//  CCConfigFactory.hpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#ifndef CCConfigFactory_hpp
#define CCConfigFactory_hpp

#include <memory>
#include <string>
#include <vector>
#include <unistd.h>

#include "CCConfig.hpp"

using namespace std;

class CCConfigFactory {
public:
    static auto make_debug(string logfile) -> CCConfig;
    static auto make_user(string basepath) -> CCConfig;
};

#endif /* CCConfigFactory_hpp */
