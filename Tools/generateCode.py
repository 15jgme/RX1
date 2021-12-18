import sys, os, io
from numpy import loadtxt  

# appending path
sys.path.append(os.path.relpath('./code_generator'))

from cpp_generator import *
from code_generator import *

script_path = os.path.realpath(__file__)
parent_path = os.path.dirname(os.path.dirname(script_path))
file_path = os.path.join(os.path.sep,parent_path,"messages", "message_list","makelist.txt")

#Messagee class header generator function
def genHeader(name, vabList):
    cpp = CppFile("../include/"+name + ".h")
    cpp("#ifndef " + name.upper() + "_H")
    cpp("#define " + name.upper() + "_H")
    with cpp.block("class " + name, ";"):
        cpp.label('public')
        cpp(name + "();") 
        for i in range(0,len(vabList)):
            cpp(vabList[i][0] + " " + vabList[i][1] + ";")
        cpp("char *getData();")
    cpp("#endif")

#Messagee class implimentation generator function
def genClass(name, vabList):
    cpp = CppFile("../src/"+name + ".cpp")
    cpp("#include \"" + name + ".h\"")
    cpp.newline(3)
    cpp(name + "::" + name + "(){}")

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

