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



// // test route to make sure everything is working (accessed at GET http://localhost:8080/api)
router.get('/', function(req, res) {


    // var options = { method: 'GET',
    // url: 'https://bldg-pi-api.ou.ad3.ucdavis.edu/piwebapi/streams/A0EbgZy4oKQ9kiBiZJTW7eugwb1fCH91qBEWKCMCkgV3FwQVnXfVra4qQ4ZlwCoJcYu6wVVRJTC1BRlxDRUZTXFVDREFWSVNcQlVJTERJTkdTXEFSQyBQQVZJTElPTlxFTEVDVFJJQ0lUWXxERU1BTkRfS0JUVQ/value',
    // headers: 
    // { 'postman-token': '03bab53f-87cb-2f22-d6a7-520432e67382',
    //     'cache-control': 'no-cache',
    //     authorization: 'Basic b3VccGktYXBpLXB1YmxpYzpNNTMkZHg3LGQzZlA4' } };

    // request(options, function (error, response, body) {
    // if (error) throw new Error(error);

    // res.json(body);
    // });

    var request = require("request");

    var options = { method: 'GET',
    url: 'https://bldg-pi-api.ou.ad3.ucdavis.edu/piwebapi/streams/A0EbgZy4oKQ9kiBiZJTW7eugwndkJpx345BGc9ZiQlqSuWwpPsU7nYqSVoPalicMj9FcQVVRJTC1BRlxDRUZTXFVDREFWSVNcQlVJTERJTkdTXFdFTExNQU4gSEFMTFxFTEVDVFJJQ0lUWXxERU1BTkRfS0JUVQ/interpolated?starttime=fri&endtime=fri%2B1d&interval=1h',
    headers: 
    { 'postman-token': '2b75794e-33aa-230f-38fe-f22628d2ec01',
        'cache-control': 'no-cache',
        authorization: 'Basic b3VccGktYXBpLXB1YmxpYzpNNTMkZHg3LGQzZlA4' } };

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