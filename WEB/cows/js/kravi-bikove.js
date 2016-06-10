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
