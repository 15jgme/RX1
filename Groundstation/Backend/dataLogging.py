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

        if (round(self.oldData[0]) != round(newData[0])) or self.firstRun:
            dict ={
                'altitude_m' : newData[1],
                'pressure' : newData[2],
                'temperature' : newData[3],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/altitude", datJson)
        if (round(self.oldData[4]) != round(newData[4])) or self.firstRun:
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
        if (round(self.oldData[15]) != round(newData[15])) or self.firstRun:
            dict ={
                'voltage' : newData[16],
                'capacity' : newData[17],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/battery", datJson)
        if (round(self.oldData[18]) != round(newData[18])) or self.firstRun:
            dict ={
                'em1_firing' : newData[19],
                'em1_fired' : newData[20],
                'em1_safe' : newData[21],
                'em1_continuity' : newData[22],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/ematch", datJson)
        if (round(self.oldData[23]) != round(newData[23])) or self.firstRun:
            dict ={
                'a1' : newData[24],
                'a2' : newData[25],
                'a3' : newData[26],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/position", datJson)
        if (round(self.oldData[27]) != round(newData[27])) or self.firstRun:
            dict ={
                'state' : newData[28],
                'sddetect' : newData[29],
                'sdok' : newData[30],
                'syshealth' : newData[31],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/commander", datJson)
        if (round(self.oldData[32]) != round(newData[32])) or self.firstRun:
            dict ={
                'sety' : newData[33],
                'setz' : newData[34],
                'offy' : newData[35],
                'offz' : newData[36],
            }
            datJson = json.dumps(dict)
            self.client.publish("RX1/motormnt", datJson)
