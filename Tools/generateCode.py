import sys, os, io
  
# appending path
sys.path.append(os.path.relpath('./code_generator'))

from cpp_generator import *
from code_generator import *

script_path = os.path.realpath(__file__)
parent_path = os.path.dirname(os.path.dirname(script_path))
file_path = os.path.join(os.path.sep,parent_path,"messages", "message_list","makelist.txt")

## Load message list 
message_list = []
with open(file_path) as file:
    for line in file:
        message_list.append(line.rstrip())
print(message_list)


# cpp = CodeFile('example.cpp')
# cpp('int i = 0;')

# x_variable = CppVariable(name='x', type='int const&', is_static=True, is_constexpr=True, initialization_value='42')
# x_variable.render_to_string(cpp)

# name_variable = CppVariable(name='name', type='char*', is_extern=True)
# name_variable.render_to_string(cpp)