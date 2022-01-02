from os import truncate
from serialComms import RX1_comms
from dataLogging import dataLogging
import csv
import time

def current_milli_time():
    return round(time.time() * 1000)

timestr = time.strftime("%Y%m%d-%H%M%S")
writeFile = "./Logs/" + timestr + ".csv"

open('tempLog.json', 'w').close() #wipe temporary log

f = open(writeFile, 'w')
writer = csv.writer(f)

firstRow = True

RX1 = RX1_comms("COM8")
print("RX1 communications initiated")

data = dataLogging()
print("Data logger started")

firstRun = True # prevent partial first reads

t0Set = False
t0 = 0

while(True):
    time.sleep(0.01) #Give the mqtt broker a little bit of a break
    if RX1.dev.in_waiting:
        RX1.update()
        if(firstRow):
            writer.writerow(RX1.names)
            RX1.dev.flushInput()
            firstRow = False
        elif RX1.valid:
            writer.writerow(RX1.data)
            if firstRun:
                firstRun = False
            elif t0Set:
                data.update(RX1.data)

            # We need to figure out what time the rocket started up at assuming  
            if not t0Set:
                indxs = [i for i,val in enumerate(RX1.names) if val=="timestamp"]
                t0 = RX1.data[indxs[1]]
                for k in range(0, len(indxs)):
                    if t0 > RX1.data[indxs[1]]:
                        t0 = RX1.data[indxs[1]]
                t0Set = True
                data.t0 = current_milli_time() - (t0 / 1000) - 2000
