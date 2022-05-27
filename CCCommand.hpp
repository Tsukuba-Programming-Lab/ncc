//
//  CCCommand.hpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#ifndef CCCommand_hpp
#define CCCommand_hpp

#include <memory>
#include <string>
#include <vector>

#include "CCLogger.hpp"
#include "CommandExecutor.hpp"

using namespace std;

class CCCommand {
private:
    shared_ptr<CCLogger> logger;
    shared_ptr<CommandExecutor> executor;
    
public:
    CCCommand(shared_ptr<CCLogger> _logger, shared_ptr<CommandExecutor> _executor);
    
    void run(vector<string> const args) const;
};

#endif /* CCCommand */
