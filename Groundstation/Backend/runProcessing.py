from serialComms import RX1_comms
import csv

f = open('./tempLog.csv', 'w')
writer = csv.writer(f)

firstRow = True

RX1 = RX1_comms("COM8")

while(True):
    if(firstRow):
        writer.writerow(RX1.names)
        firstRow = False
    RX1.update()
    print(RX1.data)
    print(RX1.names)
    writer.writerow(RX1.data)