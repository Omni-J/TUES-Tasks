var turnCounter = 1;

function arrLength() {
  var x = document.getElementById("startingNumber").value;
  if(x >= 3 && x <= 10){
    return x;
  }else{
    alert("Number length must be between 3 and 10!");
  }
}


function outputArr() {
  rightNumbers = [];
  rightNumbers.push(Math.floor((Math.random() * 9) + 1));
  while(rightNumbers.length < arrLength()){
    var rand = Math.floor((Math.random() * 9) + 0);
    if(rightNumbers.indexOf(rand) == -1){
      rightNumbers.push(rand);
    };
  };
  return rightNumbers;
}

function surrender() {
  alert("Right number is: " + rightNumbers.join(""));
}

function checking(playerNumber){
  bulls = 0, cows = 0;
  for(var i = 0; i < arrLength();i++){
    if(playerNumber[i] == rightNumbers[i]){
      bulls++;
    }else{
      for(var j = 0; j < arrLength(); j++){
        if(i != j){
          if(playerNumber[i] == rightNumbers[j]){
            cows++;
          }
        }
      }
    }
  }
  data = {bull: bulls, cow: cows};
  return data;
}

function keyPressed(key) {
	if (key.keyCode == 13) {
		var playerNum = document.getElementById("playerNumber").value;
		checker();
	}
}

function checker(){
  var playerNum = document.getElementById("playerNumber").value;
  var repeat = false;
  for(var i = 0; i < arrLength();i++){
      for(var j = 0; j < arrLength(); j++){
        if(playerNum[i] == playerNum[j] && i != j){
          repeat = true;
          break;
        }
      }
  }
  if(playerNum.length != arrLength()){
    alert("Length of this number must be exactly " + arrLength() + " numbers!");
  }else if(repeat == true){
    alert("You can't repeat numbers!");
  }else{
    var data = checking(playerNum);
    if(turnCounter == 1){
      document.getElementById("turnInfo").innerHTML = "Turn " + turnCounter + " : " + playerNum + " Bulls: " + data.bull + " , Cows: " +data.cow + "<br>";
      turnCounter++;
    }else{
      document.getElementById("turnInfo").innerHTML += "Turn " + turnCounter + " : " + playerNum + " Bulls: " + data.bull + " , Cows: " +data.cow + "<br>";
      turnCounter++;
    }
    if(data.bull == arrLength()){
      turnCounter--;
      alert("You won for " +turnCounter+ " turns! Restarting number");
      document.getElementById("turnInfo").innerHTML = "";
      turnCounter = 1;
      outputArr();
    }
  };
}

function lastStatus(){
  alert("Last time you had Bulls: " + data.bull + " and Cows: " +data.cow);
}

function restart(){
  alert("Restarting game");
  document.getElementById("turnInfo").innerHTML = "";
  turnCounter = 1;
}