let buff;

function setup() {
  createCanvas(900, 600, WEBGL);
  angleMode(DEGREES);
  noStroke();
  buff = createGraphics(300, 300);
  buff.background("white");
}

function draw() {
  background(125);

  buff.fill(255, 0, 255);
  buff.noStroke();
  buff.ellipse(random(buff.width), random(buff.height), 10, 10);
  texture(buff);

  rotateY(frameCount);
  //box(200);
  sphere(100, 30, 30);
  camera(250, -250, 250);
}
