var express = require('express');
var httpClient = require('http');
var app = new express();
var fs = require('fs');
var http = require('http');
var server = http.createServer(app);
var io = require('socket.io').listen(server);

app.use(express.static(__dirname + "/public"));


const SerialPort = require('serialport');
const Readline = SerialPort.parsers.Readline;
var port = new SerialPort('COM3', {baudRate: 9600}, function (err) 
{
	if (err) 
	{
		return console.log('Error on create : ', err.message);
	}		
});

const parser = port.pipe(new Readline({ delimiter: '\n' }));

port.on('error', function(err) 
	{
		console.log('Any Error: ', err.message);
	})

parser.on('data', function(data)
	{			
		console.log(data);		
		arduino.emit("results", {"results": data})
	})


var arduino = io.of("/arduino").on('connection', function(socket)
{
	console.log('Arduino user connected');
	
	socket.on('h', function(data) {	
		port.write("h");
	});
	socket.on('l', function(data) {	
		port.write("l");
	});

});

server.listen(3000);    
console.log("Express server listening at 3000");
