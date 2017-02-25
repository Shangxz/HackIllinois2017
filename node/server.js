var bodyParser = require('body-parser');
app.use(bodyParser.json()); // support json encoded bodies
app.use(bodyParser.urlencoded({ extended: true })); // support encoded bodies



// call the packages we need
var express    = require('express');        // call express
var app        = express();                 // define our app using express
var bodyParser = require('body-parser');
var http = require('http');
var request = require("request");

// configure app to use bodyParser()
// this will let us get the data from a POST
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

var port = process.env.PORT || 8080;        // set our port

// ROUTES FOR OUR API
// =============================================================================
var router = express.Router();              // get an instance of the express Router
var router = express.Router();



// // test route to make sure everything is working (accessed at GET http://localhost:8080/api)
router.get('/', function(req, res) {

        var request = require("request");

        var options = { method: 'POST',
        url: 'https://westus.api.cognitive.microsoft.com/text/analytics/v2.0/sentiment',
        headers: 
        { 'postman-token': 'c8f92caa-ebd2-b174-eab8-f02f24f45f05',
            'cache-control': 'no-cache',
            'content-type': 'application/json',
            'ocp-apim-subscription-key': '7e6d05389abd492b865c044eaded3f73' },
        body: { documents: [ { language: 'en', id: 'string', text: 'I have shit to do' } ] },
        json: true };

        request(options, function (error, response, body) {
        if (error) throw new Error(error);

        res.json(body);
        });

});


app.use('/api', router);

// START THE SERVER
// =============================================================================
app.listen(port);
console.log('Magic happens on port ' + port);