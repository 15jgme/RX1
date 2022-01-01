# RX1

The goal of this project is to build portable, and expansible flight software for hobby sized rockets.
While TVC is the pie in the sky, this repo will be setup so that a controller can be imported, but one won't be made publically available.

The main goals of the software are

- Telemetry
- Data logging 
- Parachute control
- State estimation
- Servo control


![RX1_telemetry](https://user-images.githubusercontent.com/47725944/147837025-ddf2a6e5-edc9-43ac-ac8d-1b8d3db4a939.gif)

## Short term goals

-Build up the flight software now that the messaging is workable
-Find ways to abstract the code to more platforms (I'd like to avoid relying on Arduino.h and the feather defines)
-Add in a config file to easily change pins and other things
-Software in the loop (using fakeArduino) spoof flight by replacing the code inside the sensors class with some flight dynamics (this should be a pretty cool one)

If we can get things a little more portable, I think this could be very helpful even for teams competing in sport rocketry like the SA Cup, and save a lot of tiresome work building groundstation and telemetry systems. 
# Any contributions are super encouraged and appreciated!

## Requirements 
- Platformio
- Python3 (and a few packages, check the setup scripts)
- An MQTT broker (only tested with mosquitto)
- Grafana or plotjuggler (<-- probably less of a headache but less pretty) for visualization
- 🚀🚀🚀 lots of rocket emojis

## Making a new topic 
If you want to add a new topic (or add variables to an existing topic) it is super easy!
First make a new message file <yourmessage>.msg inside **/messages/message_list/**
  
This file contains the variables inside your new message topic, comments are lines beginning with an '#'
Each line representing a variable must begin with its data type (eg int, float, uint8_t), this is coppied straight into C++ so make sure what ever you choose is supported by C++ or by the defines in the Arduino header
Next is the variable name this can be anything as its not sent to the groundstation each time

Once you're finished you should have a file with rows looking like this (watch for unintentional spaces and mixing comments with message descriptions isn't supported yet)
 
  **parachute.msg**
  ```
  bool continuity
  bool fired
  float time_delay
  ```
Now open the makelist.txt and add your new topic to one of the list rows

All thats left to do is generate the flight computer and groundstation code (hopefully this will be automatic soon)
**flight codegen**
  first cd to /Tools/ 
  then run python generateCode.py in your terminal
**groundstation codegen**
  first cd to /Groundstation/Backend 
  then run python generateGSCode.py in your terminal
  
Now when you build your code you should have access to a new object inside the msg object, msg.yourmessage !
msg.yourmessage holds all your variables.
  
## Usage of the message system on the flight computer
The message structure was designed to help reduce redundant processing on the flight computer. 
For example, why run your apogee detection algorithem if there's no new altitude data? 

To account for this, RX1 messages topics all contain a timestamp variable (no need to include it in your .msg file it's built for you 😉). 
Variables in RX1 message topics all must be updated using msg.yourmessage.set<variable>(newData), and returned by msg.yourmessage.get<variable>(newData). 
When ever the set funtion is run (so long as the newData is different from what's already there) the timestamp is updated.
The timestamp is accessed by msg.yourmessage.timestamp (it's the only non-private variable in the topic).

To prevent, lets say your apogee detector from running on stale data for example, you can save the last data timestamp you ran the detector on.
Lets call this ```oldTs```, when your detector needs to run, simply only run it ```if(oldTS < msg.parachute.timestamp) {run detector}```
                                                                                                                   
### One more quick note on the central message object
The **msg** object is declared globally so you can access your topics anywhere!
```msg.getData()``` returns a string (hopefully will change to a char* soon) containing all data stored by the message object in a predictable order that the groundstation expects and automatically parses.
                                                                                                                      
                                                                                                                      
                                                                                                                      
## Telemetry 
Now the fun part! Running **runProcessing.py** from inside /Groundstation/Backend will listen to serial data from something like an xbee split it into topics and publish it to your friendly local MQTT broker (tested with mosquitto), you just need to change the hostname in generateGSCode.py (will fix soon!). 
Then to visualize the data you should be able to use Grafana, or plotjuggler.
                                                                                                                      
**PS** runProcessing.py will also save the telemetry data it gets to a csv in /Groundstation/Backend/Logs just in case something really bad happens to your vehicle 💥                                                                                                                  
                                                                                                                      
                                                                                                                      
                                                                                                                    
                                                                            
  

  
  
