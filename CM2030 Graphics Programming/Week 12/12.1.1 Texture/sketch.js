let img;

function preload() {
  img = loadImage('assets/rocks.jpg');
}

function setup() {
  createCanvas(900, 600, WEBGL);
  angleMode(DEGREES);
}

function draw() {
  background(125);
  texture(img);
  rotateY(frameCount);
  box(300);
  camera(250, -500, 500);
}
