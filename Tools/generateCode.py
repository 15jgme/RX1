initVals = True # true if variales should be initialized with zeros/false

import sys, os, io
from numpy import loadtxt  

# appending path
sys.path.append(os.path.relpath('./code_generator'))

from cpp_generator import *
from code_generator import *

script_path = os.path.realpath(__file__)
parent_path = os.path.dirname(os.path.dirname(script_path))
file_path = os.path.join(os.path.sep,parent_path,"messages", "message_list","makelist.txt")

#Message class header generator function
def genHeader(name, vabList):
    cpp = CppFile("../include/"+name + ".h") 
    cpp("#include <Arduino.h>")
    cpp("#ifndef " + name.upper() + "_H")
    cpp("#define " + name.upper() + "_H")
    with cpp.block("class " + name, ";"):
        # Make variables
        for i in range(0,len(vabList)): 
            if initVals:
                if (vabList[i][0]=="float"):
                    cpp(vabList[i][0] + " " + vabList[i][1] + " = 0.0f;")
                elif (vabList[i][0]=="bool"):
                    cpp(vabList[i][0] + " " + vabList[i][1] + " = false;")
                else:
                    cpp(vabList[i][0] + " " + vabList[i][1] + " = 0.0f;")
            else:
                cpp(vabList[i][0] + " " + vabList[i][1] + " = 0.0f;")
        cpp.label('public')
        cpp("uint32_t sample = 0;")
        #Variable access functions
        for i in range(0,len(vabList)):
            cpp("void set" + vabList[i][1] + "(" + vabList[i][0] + " newVal);") #set 
            cpp(vabList[i][0] + " get" + vabList[i][1] + "();") #get
        cpp(name + "();") 
        cpp("String getData();")
    cpp("#endif")

#Message class implimentation generator function
def genClass(name, vabList):
    cpp = CppFile("../src/messages/" + name + ".cpp")
    cpp("#include \"" + name + ".h\"")
    cpp.newline(3)
    cpp(name + "::" + name + "(){}")

    with cpp.block("String " + name + "::" + "getData()"):
        vabNames = []
        writeOutStr = ""
        for i in range(0,len(vabList)):
            vabNames.append(vabList[i][1])
            # writeOutStr = writeOutStr + "String(" + name + "::" + vabNames[i] + ")"
            writeOutStr = writeOutStr + "String(" + vabNames[i] + ")"
            if i != len(vabList)-1:
                writeOutStr = writeOutStr + "+\",\"+"
        cpp("String datMsg = " + writeOutStr + ";")
        cpp("return datMsg;")

    for i in range(0, len(vabList)):
        with cpp.block(vabList[i][0] + " " + name + "::" + "get" + vabList[i][1] + "()"):
            cpp("sample ++;")
            cpp("return " + vabList[i][1] + ";")
        cpp.newline(1)
        with cpp.block("void " + name + "::" + "set" + vabList[i][1] + "(" + vabList[i][0] +" newVal)"):
            cpp("sample ++;")
            cpp(vabList[i][1] + " = newVal;")
        cpp.newline(1)



#Message class
def genMsgHeader(nameList):
    cpp = CppFile("../include/messages.h") 
    cpp("#ifndef MESSAGES_H")
    cpp("#define MESSAGES_H")
    cpp("#include <arduino.h>")

    for i in range(0, len(nameList)):
        cpp("#include \"" + nameList[i] + ".h\"")
    with cpp.block("class messages", ";"):
        cpp.label('public')
        cpp("messages();")
        for i in range(0, len(nameList)):
            cpp(nameList[i] + " " + nameList[i] + "_t;") #Maybe don't need pointer?
        cpp("String getData();")
    cpp("#endif")

def genMsgClass(nameList):
    cpp = CppFile("../src/messages/messages.cpp")
    cpp("#include \"messages.h\"")
    cpp.newline(1)
    cpp("messages::messages(){}")

    with cpp.block("String messages::getData()"):
        vabNames = []
        writeOutStr = ""
        for i in range(0,len(nameList)):
            vabNames.append(nameList[i])
            writeOutStr = writeOutStr + nameList[i]+"_t.getData()"
            if i != len(nameList)-1:
                writeOutStr = writeOutStr + "+\",\"+"
        cpp("String datMsg = " + writeOutStr + ";")
        cpp("return datMsg;")

## Load message list 
message_list = []
with open(file_path) as file:
    for line in file:
        #Read message build list
        message_list.append(line.rstrip())
        filename = message_list[-1] + ".msg"
        path = os.path.join(os.path.sep,parent_path,"messages", "message_list", filename)
        list_of_lists = []

        #Read desired variables for all messages in message list
        with open(path) as f:
            for line in f:
                inner_list = [elt.strip() for elt in line.split(' ')]
                if not ("#" in inner_list[0]):
                    list_of_lists.append(inner_list)
        

        genHeader(message_list[-1], list_of_lists)
        genClass(message_list[-1], list_of_lists)
        print(message_list[-1] + " message class generated...")
    genMsgHeader(message_list)
    genMsgClass(message_list)
## CLASS STRUCTURE ##

# Vab 1
# Vab 2
# .....
# Vab n

# Priority

# Unique identifier 

# >> Function <<
# write_log 
# -> ['$Unique identifier$', Vab1, Vab2, ..., Vabn]

## End of class structure ##

