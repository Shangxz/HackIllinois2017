var express = require('express');
var BinaryServer = require('binaryjs').BinaryServer;
//var fs = require('fs');
var wav = require('wav');

var https = require('https');
var fs = require('fs');

var options = {
  key: fs.readFileSync('/etc/ssl/private/server.key'),
  cert: fs.readFileSync('/etc/ssl/certs/server.crt')
};

var port = 3700;
var porthttps = 8443;
var outFile = 'demo.wav';
var app = express();

app.set('views', __dirname + '/tpl');
app.set('view engine', 'jade');
app.engine('jade', require('jade').__express);
app.use(express.static(__dirname + '/public'))

app.get('/', function(req, res){
  res.render('index');
});

app.get('/api', function(req,res){
  res.render('page', {text: 'hello'});
});

app.listen(port);

https.createServer(options, function (req, res) {
  res.writeHead(200);
  res.end("Welcome to Node.js HTTPS Servern");
}).listen(porthttps);

console.log('server open on port ' + port);
console.log('https server open on port '+ porthtpps);

binaryServer = BinaryServer({port: 9001});

binaryServer.on('connection', function(client) {
  console.log('new connection');

  var fileWriter = new wav.FileWriter(outFile, {
    channels: 1,
    sampleRate: 48000,
    bitDepth: 16
  });

  client.on('stream', function(stream, meta) {
    console.log('new stream');
    stream.pipe(fileWriter);

    stream.on('end', function() {
      fileWriter.end();
      console.log('wrote to file ' + outFile);
    });
  });
});
