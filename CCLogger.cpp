//
//  CCLogger.cpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#include "CCLogger.hpp"

CCLogger::~CCLogger() {
    log_separator("End");
}

void CCLogger::loginput(shared_ptr<CCExecutionInput> input) {
    log_separator("Command");
    cout << endl;
    writer->p(input->commandline)->endl();
        
    for (auto file: input->file_contents) {
        log_separator(file.first);
        writer->p(file.second)->endl();
    }
}

void CCLogger::logresult(shared_ptr<CommandResult> result) {
    log_separator("Status");
    if (result->kind == CommandResult::Kind::Success) {
        writer->p("Success")->endl();
    } else {
        writer->p("Failure")->p("(")->p(result->exit_code)->p(")")->endl();
    }
    log_separator("Output");
    writer->p(result->output)->endl();
}

void CCLogger::close() {
    writer->close();
}

void CCLogger::log_separator(string name) {
    writer->p("-----ncc")->p(uuid)->p("-----")->endl();
    writer->p(":")->p(name)->p(":")->endl();
}
