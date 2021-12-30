# import json

try:
    import ujson as json
except ImportError:
    try:
        import simplejson as json
    except ImportError:
        import json

storageFile = "tempLog.json"

class dataLogging:
    def __init__(self):
        self.data = {}
        self.t0 = 0
        self.oldData = []
        self.firstRun = True
        self.data['altitude'] = []
        self.data['attitude'] = []
        self.data['battery'] = []
        self.data['ematch'] = []
        self.data['position'] = []
        self.data['commander'] = []


    def update(self,newData):
        if self.firstRun:
            self.oldData = newData
            self.firstRun = False

        if round(self.oldData[0]) != round(newData[0]):
            self.data['altitude'].append({
                'timestamp' : newData[0]/1000 + self.t0,
                'altitude_m' : newData[1],
                'pressure' : newData[2],
                'temperature' : newData[3],
            })
        if round(self.oldData[4]) != round(newData[4]):        
            self.data['attitude'].append({
                'timestamp' : newData[4]/1000 + self.t0,
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
        if round(self.oldData[15]) != round(newData[15]):
            self.data['battery'].append({
                'timestamp' : newData[15]/1000 + self.t0,
                'voltage' : newData[16],
                'capacity' : newData[17],
            })
        if round(self.oldData[18]) != round(newData[18]):
            self.data['ematch'].append({
                'timestamp' : newData[18]/1000 + self.t0,
                'em1_firing' : newData[19],
                'em1_fired' : newData[20],
                'em1_safe' : newData[21],
                'em1_continuity' : newData[22],
                'em2_firing' : newData[23],
                'em2_fired' : newData[24],
                'em2_safe' : newData[25],
                'em2_continuity' : newData[26],
            })
        if round(self.oldData[27]) != round(newData[27]):
            self.data['position'].append({
                'timestamp' : newData[27]/1000 + self.t0,
                'a1' : newData[28],
                'a2' : newData[29],
                'a3' : newData[30],
            })
        if round(self.oldData[31]) != round(newData[31]):
            self.data['commander'].append({
                'timestamp' : newData[31]/1000 + self.t0,
                'state' : newData[32],
            })
        with open('tempLog.json', 'w') as outfile:
            json.dump(self.data, outfile)