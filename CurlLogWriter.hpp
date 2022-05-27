//
//  CurlLogWriter.hpp
//  ncc
//
//  Created by yuki on 2022/05/27.
//

#ifndef CurlLogWriter_hpp
#define CurlLogWriter_hpp

#include "StringWriter.hpp"

#include <sstream>
#include <curl/curl.h>


class CurlLogWriter: public StringWriter {
private:
    bool debug;
    string username;
    
    stringstream buffer;
public:
    CurlLogWriter(bool _debug, string _username) : debug(_debug), username(_username) {
    }
    
    void write(string data) override {
        buffer << data;
    }
    
    void close() override {
        auto logdata = buffer.str();
        
    }
};


#endif /* CurlLogWriter_hpp */
