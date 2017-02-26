
function wait(ms){
   var start = new Date().getTime();
   var end = start;
   while(end < start + ms) {
     end = new Date().getTime();
  }
}

// Add a single command
var commandHello = {
    indexes:["hello","lets see what u got","hey", "i am home"], // These spoken words will trigger the execution of the command
    action:function(){ // Action to be executed when a index match with spoken word
        //artyom.say("Hey buddy ! How are you today?");
     while(true){
        startRecognition();
        wait(20000); //waits for 20 seconds.
        stopRecognition();
     }  
        
    }
};

artyom.addCommands(commandHello); // Add the command with addCommands method. Now

// print the text that is recognized 

artyom.redirectRecognizedTextOutput(function(recognized,isFinal){
    var span = document.getElementById('output');

    if(isFinal){
        span.innerHTML = '';
        console.log("Final recognized text: " + recognized);
    }else{
        span.innerHTML = recognized;
        console.log(recognized);
    }
});

function simulate(){
  artyom.simulateInstruction("home");
}
// function that initializes  and starts listening 
function startOneCommandArtyom(){

    artyom.fatality();// use this to stop any of

     setTimeout(function(){// if you use artyom.fatality , wait 250 ms to initialize again.
         artyom.initialize({
            lang:"en-US",// A lot of languages are supported. Read the docs !
            continuous:false,// recognize 1 command and stop listening !
            listen:true, // Start recognizing
            debug:true, // Show everything in the console
            speed:1 // talk normally
        });
    },250);
}

// speech to text 

var settings = {
    continuous:false, // Don't stop never because i have https connection
    onResult:function(text){
        // text = the recognized text
        console.log(text);
        var request = require("request");

var options = { method: 'POST',
  url: 'http://localhost:8080/api',
  headers: 
   { 'postman-token': '57cfa97a-d1ea-b12a-c04a-e37aacdd363a',
     'cache-control': 'no-cache' },
  body: text };

request(options, function (error, response, body) {
  if (error) throw new Error(error);

  console.log(body);
});

    },
    onStart:function(){
        console.log("Dictation started by the user");
    },
    onEnd:function(){
        console.log("Dictation stopped after 10 sec");
    }
};

var UserDictation = artyom.newDictation(settings);

function startRecognition(){
  UserDictation.start();
}

function stopRecognition(){
  UserDictation.stop();

}