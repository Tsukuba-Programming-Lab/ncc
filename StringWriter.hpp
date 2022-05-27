//
//  StringWriter.hpp
//  ncc
//
//  Created by yuki on 2022/05/27.
//

#ifndef String_Writer_hpp
#define String_Writer_hpp

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class StringWriter {
public:
    virtual void write(string data) = 0;
    virtual void close() {};
    
    virtual StringWriter* p(string data) { this->write(data); return this; }
    virtual StringWriter* p(int data) { return this->p(to_string(data)); }
    virtual StringWriter* p(float data) { return this->p(to_string(data)); }
    
    virtual void endl() { this->p("\n"); }
};

class DebugStringWriter: public StringWriter {
public:
    DebugStringWriter() {}
    void write(string data) override { cout << data; }
};

class FileStringWriter: public StringWriter {
private:
    ofstream log_file;
public:
    FileStringWriter(string log_path) {
        this->log_file = ofstream(log_path, ios::app);
    }
    void write(string data) override {
        this->log_file << data;
    };
};

#endif /* StringWriter */
