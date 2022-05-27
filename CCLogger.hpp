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
#include "CCExecutionInput.hpp"
#include "CommandResult.hpp"
#include "StringWriter.hpp"

using namespace std;

class CCLogger {
private:
    shared_ptr<StringWriter> writer;
    string uuid;
    
public:
    CCLogger(shared_ptr<StringWriter> _writer) : writer(_writer) {
        this->uuid = Uuid::newUuid().toString();
        
        log_separator("Bigin");
    }

    ~CCLogger();
    
    void loginput(shared_ptr<CCExecutionInput> input);
    void logresult(shared_ptr<CommandResult> result);
    void close();
private:
    void log_separator(string name);
};


#endif /* CCLogger_hpp */
