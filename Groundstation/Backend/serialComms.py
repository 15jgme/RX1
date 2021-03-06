from os import name
import serial
import pickle

filename = "../../Tools/message_identity.pkl"

class RX1_comms:
    def __init__(self,port):
        self.comm_port = port
        dev = serial.Serial("COM8", 115200, timeout=20)
        self.dev = dev
        self.msg = ""

        #load names list
        open_file = open(filename, "rb")
        loadedData = pickle.load(open_file)
        self.names = loadedData[0]
        self.topic = loadedData[1]
        self.valid = False
        open_file.close()

        self.firstRun = True
    
    def update(self):
        if self.firstRun:
            self.dev.flush()
            self.firstRun = False
        self.msg = str(self.dev.readline()[0: -2].decode("utf-8"))
        try:
            self.data = list(map(float, self.msg.split(",")))
            if len(self.data) == len(self.names):
                self.valid = True
            else:
                self.valid = False
            
        except:
            print("ERROR: Incomplete message")
            self.valid = False
        # self.dev.flushInput()
        
        
