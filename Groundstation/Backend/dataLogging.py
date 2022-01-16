import json
import paho.mqtt.client as mqtt

class dataLogging:
    def __init__(self):
        self.data = {}
        self.t0 = 0
        self.oldData = []
        self.firstRun = True

        self.i = 0
        
        broker_address="LAPTOP-R70PIQ08" 
        self.client = mqtt.Client("RX1_1") #create new instance
        self.client.connect(broker_address, 1883) #connect to broker


    def update(self,newData):
        if self.firstRun:
            self.oldData = newData
            self.firstRun = False

        if (round(self.oldData[0]) != round(newData[0])) or self.firstRun or (self.i % 20 == 0):
            dict ={
                'altitude_m' : newData[1],
                'pressure' : newData[2],
                'temperature' : newData[3],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/altitude", datJson)
        if (round(self.oldData[4]) != round(newData[4])) or self.firstRun or (self.i % 20 == 0):
            dict ={
                'q1' : newData[5],
                'q2' : newData[6],
                'q3' : newData[7],
                'q4' : newData[8],
                'w1' : newData[9],
                'w2' : newData[10],
                'w3' : newData[11],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/attitude", datJson)
        if (round(self.oldData[12]) != round(newData[12])) or self.firstRun or (self.i % 20 == 0):
            dict ={
                'voltage' : newData[13],
                'capacity' : newData[14],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/battery", datJson)
        if (round(self.oldData[15]) != round(newData[15])) or self.firstRun or (self.i % 20 == 0):
            dict ={
                'em1_firing' : newData[16],
                'em1_fired' : newData[17],
                'em1_safe' : newData[18],
                'em1_continuity' : newData[19],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/ematch", datJson)
        if (round(self.oldData[20]) != round(newData[20])) or self.firstRun or (self.i % 20 == 0):
            dict ={
                'a1' : newData[21],
                'a2' : newData[22],
                'a3' : newData[23],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/position", datJson)
        if (round(self.oldData[24]) != round(newData[24])) or self.firstRun or (self.i % 20 == 0):
            dict ={
                'state' : newData[25],
                'sddetect' : newData[26],
                'sdok' : newData[27],
                'syshealth' : newData[28],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/commander", datJson)
        if (round(self.oldData[29]) != round(newData[29])) or self.firstRun or (self.i % 20 == 0):
            dict ={
                'sety' : newData[30],
                'setz' : newData[31],
                'offy' : newData[32],
                'offz' : newData[33],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/motormnt", datJson)
        self.i = self.i + 1
