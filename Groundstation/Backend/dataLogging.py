import json
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

        if round(self.oldData[0]) != round(newData[0]):
            dict ={
                'altitude_m' : newData[1],
                'pressure' : newData[2],
                'temperature' : newData[3],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/altitude", datJson)
        if round(self.oldData[4]) != round(newData[4]):
            dict ={
                'q1' : newData[5],
                'q2' : newData[6],
                'q3' : newData[7],
                'q4' : newData[8],
                'w1' : newData[9],
                'w2' : newData[10],
                'w3' : newData[11],
                'alph1' : newData[12],
                'alph2' : newData[13],
                'alph3' : newData[14],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/attitude", datJson)
        if round(self.oldData[15]) != round(newData[15]):
            dict ={
                'voltage' : newData[16],
                'capacity' : newData[17],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/battery", datJson)
        if round(self.oldData[18]) != round(newData[18]):
            dict ={
                'em1_firing' : newData[19],
                'em1_fired' : newData[20],
                'em1_safe' : newData[21],
                'em1_continuity' : newData[22],
                'em2_firing' : newData[23],
                'em2_fired' : newData[24],
                'em2_safe' : newData[25],
                'em2_continuity' : newData[26],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/ematch", datJson)
        if round(self.oldData[27]) != round(newData[27]):
            dict ={
                'a1' : newData[28],
                'a2' : newData[29],
                'a3' : newData[30],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/position", datJson)
        if round(self.oldData[31]) != round(newData[31]):
            dict ={
                'state' : newData[32],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/commander", datJson)
