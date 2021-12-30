import json

storageFile = "tempLog.json"

class dataLogging:
    def __init__(self):
        self.data = {}
    
    def update(self,newData):
        
        self.data['altitude'] = []
        self.data['altitude'].append({
            'timestamp' : newData[0],
            'altitude_m' : newData[1],
            'pressure' : newData[2],
            'temperature' : newData[3],
        })
        self.data['attitude'] = []
        self.data['attitude'].append({
            'timestamp' : newData[4],
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
        })
        self.data['battery'] = []
        self.data['battery'].append({
            'timestamp' : newData[15],
            'voltage' : newData[16],
            'capacity' : newData[17],
        })
        self.data['ematch'] = []
        self.data['ematch'].append({
            'timestamp' : newData[18],
            'em1_firing' : newData[19],
            'em1_fired' : newData[20],
            'em1_safe' : newData[21],
            'em1_continuity' : newData[22],
            'em2_firing' : newData[23],
            'em2_fired' : newData[24],
            'em2_safe' : newData[25],
            'em2_continuity' : newData[26],
        })
        self.data['position'] = []
        self.data['position'].append({
            'timestamp' : newData[27],
            'a1' : newData[28],
            'a2' : newData[29],
            'a3' : newData[30],
        })
        self.data['commander'] = []
        self.data['commander'].append({
            'timestamp' : newData[31],
            'state' : newData[32],
        })
        with open('tempLog.json', 'a') as outfile:
            json.dump(self.data, outfile)
