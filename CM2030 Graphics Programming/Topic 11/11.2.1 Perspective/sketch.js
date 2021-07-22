function setup() {
  createCanvas(900, 600, WEBGL);
  angleMode(DEGREES);
}

function draw() {
  background(125);
  normalMaterial();
  camera(0, -200, height, 0, 0, 0, 0, 1, 0);
  // fit more objects
  perspective(100);
  // changing aspect ratio
  perspective(100, width/height, mouseY, mouseX);

  for(let i=-600; i<=600; i+=100)
  {
    push();
    translate(i, 0, 0);
    box(80, 80, 500);
    pop();
  }
}
