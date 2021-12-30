import dash
from dash import dcc
from dash import html
from dash.dependencies import Input, Output
import plotly.express as px
import csv

def myFloat(myList):
    return map(float, myList)

datCsv = csv.reader(open("tempLog.csv"))
next(datCsv, None)  # skip the headers
data = list(map(myFloat, list(datCsv)))
# data = [ float(x) for x in list(datCsv) ]
print(data)

app = dash.Dash(__name__)

app.layout = html.Div([
    dcc.Graph(id="graph"),
    html.Button("Switch Axis", id='btn', n_clicks=0)
])

@app.callback(
    Output("graph", "figure"), 
    [Input("btn", "n_clicks")])

def display_graph(n_clicks):
    if n_clicks % 2 == 0:
        x, y = 'AAPL_x', 'AAPL_y'
    else:
        x, y = 'AAPL_y', 'AAPL_x'

    # fig = p
    return fig

app.run_server(debug=True)