from serialComms import RX1_comms
from dataLogging import dataLogging
import csv
import time

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



while(True):
    if(firstRow):
        writer.writerow(RX1.names)
        firstRow = False
    RX1.update()

    # print(RX1.data)
    # print(RX1.names)
    writer.writerow(RX1.data)
    if firstRun:
        firstRun = False
    else:
        data.update(RX1.data)