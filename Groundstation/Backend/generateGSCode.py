initVals = True # true if variales should be initialized with zeros/false

file_path = "../../messages/message_list/makelist.txt"

#Variables list this stores the names of data output by the getData function in the correct order.
vab_names_list = []
topic_names_list = []

#
open('dataLogging.py', 'w').close()
f = open("dataLogging.py", "a")
classSetup = """import json

storageFile = \"tempLog.json\"

class dataLogging:
    def __init__(self):
        self.data = {}
    
    def update(self,newData):
        """
print(classSetup, file=f)

i = 0 #iterator for place in output string

## Load message list 
message_list = []
with open(file_path) as file:
    for line in file:
        #Read message build list
        message_list.append(line.rstrip())
        filename = message_list[-1] + ".msg"
        path = "../../messages/message_list/" + filename
        list_of_lists = []
        print("        self.data[\'" + message_list[-1] + "\'] = []", file = f)
        print("        self.data[\'" + message_list[-1] + "\'].append({", file = f)
        print("            \'timestamp\' : newData[" + str(i) + "],", file=f)
        i = i + 1
        #Read desired variables for all messages in message list
        with open(path) as f2:
            for line in f2:
                inner_list = [elt.strip() for elt in line.split(' ')]
                if not ("#" in inner_list[0]):
                    list_of_lists.append(inner_list)
                    vab_names_list.append(inner_list[1])
                    topic_names_list.append(message_list[-1])
                    print("            \'" + inner_list[-1] + "\' : newData[" + str(i) + "],", file=f)
                    i = i + 1
        print("        })", file=f)
                    
        
endStr = """        with open(\'tempLog.json\', \'a\') as outfile:
            json.dump(self.data, outfile)"""
print(endStr, file=f)