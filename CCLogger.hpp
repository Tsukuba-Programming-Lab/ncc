//
//  CCLogger.hpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#ifndef CCLogger_hpp
#define CCLogger_hpp

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

#include "uuid.hpp"
#include "CCConfig.hpp"
#include "CCExecutionInput.hpp"
#include "CommandResult.hpp"

using namespace std;

class CCLogger {
private:
    ofstream logfile;
    string uuid;
    
public:
    CCLogger(CCConfig config);
    ~CCLogger();
    
    void loginput(shared_ptr<CCExecutionInput> input);
    void logresult(shared_ptr<CommandResult> result);
private:
    void log_separator(string name);
};


#endif /* CCLogger_hpp */
