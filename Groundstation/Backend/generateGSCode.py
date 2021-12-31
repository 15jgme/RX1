initVals = True # true if variales should be initialized with zeros/false

file_path = "../../messages/message_list/makelist.txt"

#Variables list this stores the names of data output by the getData function in the correct order.
vab_names_list = []
topic_names_list = []

#
open('dataLogging.py', 'w').close()
f = open("dataLogging.py", "a")
classSetup = """import json
import paho.mqtt.client as mqtt

class dataLogging:
    def __init__(self):
        self.data = {}
        self.t0 = 0
        self.oldData = []
        self.firstRun = True
        
        broker_address="LAPTOP-R70PIQ08" 
        self.client = mqtt.Client("RX1_1") #create new instance
        self.client.connect(broker_address, 1883) #connect to broker


    def update(self,newData):
        if self.firstRun:
            self.oldData = newData
            self.firstRun = False
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
        print("        if round(self.oldData[" + str(i) + "]) != round(newData[" + str(i) + "]):", file = f)
        print("            dict ={", file = f)
        # print("            \'timestamp\' : newData[" + str(i) + "],", file=f)
        i = i + 1
        #Read desired variables for all messages in message list
        with open(path) as f2:
            for line in f2:
                inner_list = [elt.strip() for elt in line.split(' ')]
                if not ("#" in inner_list[0]):
                    list_of_lists.append(inner_list)
                    vab_names_list.append(inner_list[1])
                    topic_names_list.append(message_list[-1])
                    print("                \'" + inner_list[-1] + "\' : newData[" + str(i) + "],", file=f)
                    i = i + 1
        print("            }", file=f)
        print("            datJson = json.dumps(dict)", file=f)
        print("            self.client.publish(\"RX1/"+message_list[-1]+"\", datJson)", file=f)
                    
