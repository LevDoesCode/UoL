function setup() {
  createCanvas(500, 500, WEBGL);
  angleMode(DEGREES);
}

function draw() {
  background(125);
  rectMode(CENTER);
  //rotateX(frameCount);
  rotateY(frameCount);
  translate(200, 0, 0);
  //rotateZ(frameCount);
  rect(0, 0, 100, 100);
  box(75);
}