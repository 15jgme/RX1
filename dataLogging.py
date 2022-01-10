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

