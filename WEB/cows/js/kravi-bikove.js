var turns = 1;
/*
fuq
//Purpose: randomy generate number with a seed nuber length
function getRandomInt(seed) {
    var legnth = 1;
    while(seed > 1){
      lenght = lenght * 10;
      seed--;
    }
    // if seed  6 then length = 100000
    return Math.floor(length + Math.random() * (9*lenght);
}
*/

function KeyPressed(key) {
  if (key.keyCode == 13) {
    var playerNum = document.getElementById("playerN").value;
    checker();
  }
}

function Surrender() {
  alert("The correct number is: " + rightN.join(""));
  Restart();
}

function Restart(){
  alert("Restarting game");
  document.getElementById("turnInfo").innerHTML = "";
  turns = 1;
  GenerateRand();
}

function Length() {
  var i = document.getElementById("startingNumber").value;
  if(i >= 3 && i <= 10){
    return i;
  }else{
    alert("Length must be between 3 and 10!");
  }
}

function GenerateRand() {
  rightN = [];
  rightN.push(Math.floor((Math.random() * 9) + 1)); // no 0
  while(rightN.length < Length()){
    var rand = Math.floor((Math.random() * 9) + 0);
    if(rightN.indexOf(rand) == -1){
      rightN.push(rand);
    };
  };
  return rightN;
}

function checking(playerN){
  bulls = 0, cows = 0;
  for(var i = 0; i < Length();i++){
    if(playerN[i] == rightN[i]){
      bulls++;
    }else{
      for(var j = 0; j < Length(); j++){
        if(i != j){
          if(playerN[i] == rightN[j]){
            cows++;
          }
        }
      }
    }
  }
  data = {bull: bulls, cow: cows};
  return data;
}


function checker(){
  var playerNum = document.getElementById("playerN").value;
  var repeat = false;
  for(var i = 0; i < Length();i++){
      for(var j = 0; j < Length(); j++){
        if(playerNum[i] == playerNum[j] && i != j){
          repeat = true;
          break;
        }
      }
  }
  if(playerNum.length != Length()){
    alert("Length of this number must be exactly " + Length() + " numbers!");
  }else if(repeat == true){
    alert("You can't repeat numbers!");
  }else{
    var data = checking(playerNum);
    if(turns == 1){
      document.getElementById("turnInfo").innerHTML = "Turn " + turns + " : " + playerNum + " Bulls: " + data.bull + " , Cows: " +data.cow + "<br>";
      turns++;
    }else{
      document.getElementById("turnInfo").innerHTML += "Turn " + turns + " : " + playerNum + " Bulls: " + data.bull + " , Cows: " +data.cow + "<br>";
      turns++;
    }
    if(data.bull == Length()){
      alert("You won for " +turns+ " turns! Restarting number");
      Restart();
    }
  };
}
