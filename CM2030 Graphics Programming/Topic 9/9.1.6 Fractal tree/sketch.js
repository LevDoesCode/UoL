// Code from a modified Daniel Shiffman example
// https://thecodingtrain.com/

var angle = 0;
var seed;
let r = 54;
let g = 34;
let b = 4;
//let a = 255;

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
  let wind = noise(frameCount/50) * 10;
  branch(100, 5, 255, wind);
  a = 255;
  //noLoop();
}
/////////////////////////////////////////////////
function branch(len, thickness, a, w) {
  stroke(color(r, g, b, a));
  if(a>50)
    a = a-20;

  strokeWeight(thickness);
  line(0, 0, 0, -len);
  translate(0, -len);

  if (len > 4)
  {
    push();
    rotate(angle + random(-10, -35) + w);
    branch(len * (0.67 + random(0.0, 0.05)), thickness*0.8, a, w);
    pop();
    push();
    rotate(-angle + random(10, 35) + w);
    branch(len * (0.67 + random(0.0, 0.05)), thickness*0.8, a, w);
    pop();
  }
  else
  {
    fill(random(100, 255), 30, 20, 100);
    let len = thickness * 25
    ellipse(0, 0, len, len);
  }
}
