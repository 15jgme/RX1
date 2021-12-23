import serial
import pickle

filename = "../../Tools/message_identity.pkl"

class RX1_comms:
    def __init__(self,port):
        self.comm_port = port
        dev = serial.Serial("COM8", 9600)
        self.dev = dev
        self.msg = ""

        #load names list
        open_file = open(filename, "rb")
        self.names = pickle.load(open_file)
        open_file.close()
    
    def update(self):
        self.msg = str(self.dev.readline()[0: -2].decode("utf-8"))
        self.data = list(map(float, self.msg.split(",")))
        
        
