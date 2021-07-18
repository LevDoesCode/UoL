// Code from a modified Daniel Shiffman example
// https://thecodingtrain.com/

var angle = 0;
var seed;

function setup() {
  createCanvas(400, 400);
  seed = random(1000);
}
////////////////////////////////////////////////
function draw() {
  background(225);
  angleMode(DEGREES);
  randomSeed(seed);
  angle = 45;
  stroke(255);
  translate(200, height);
  branch(100, 3);
}
/////////////////////////////////////////////////
function branch(len, thickness) {
  stroke(0);
  strokeWeight(thickness);
  line(0, 0, 0, -len);
  translate(0, -len);
  if (len > 4) {
    push();
    rotate(angle);
    branch(len * 0.67, thickness*0.8);
    pop();
    push();
    rotate(-angle);
    branch(len * 0.67, thickness*0.8);
    pop();
  }
}
