#!/usr/bin/python
# -*- coding: utf-8 -*-

import cgi
import sys
import os
import json
import base64

class InputParser:
    def __init__(self, form):
        json_data = json.loads(form.value)        
        self.username = json_data["user"]
        self.logdata = base64.decode(json_data["logdata"])
    
class LogWriter:
    def __init__(self, logdir):
        self.logdir = logdir
        
        if not os.path.exists(logdir):
            os.makedirs(logdir)
        elif not os.path.isdir(logdir):
            os.remove()
            os.makedirs(logdir)
            
    def log(self, username, logdata):
        logpath = "{}/{}.log".format(self.logdir, username)
        with open(logpath, "a") as f:
            f.write(logdata)
                

try:
    print("Content-Type: application/json")
    print("")

    form = cgi.FieldStorage()
    parser = InputParser(form)
    logger = LogWriter("log")
    
    logger.log(parser.username, parser.logdata)  

    print("{ \"success\": true }")
except Exception as e:
    print("{ \"success\": false }")

