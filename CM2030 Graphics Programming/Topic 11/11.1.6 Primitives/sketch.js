let angle = 0;

function setup() {
  createCanvas(900, 600, WEBGL);
  angleMode(DEGREES);
}

function draw() {
  background(125);

  normalMaterial(255);

  push();
  translate(-300, -100, 0);
  rotateX(angle);
  rotateY(angle);
  plane(100, 100);
  pop();
  
  push();
  translate(0, -100, 0);
  rotateX(angle);
  rotateY(angle);
  box(100, 100);
  pop();
  
  push();
  translate(-300, -100, 0);
  rotateX(angle);
  rotateY(angle);
  plane(100, 100);
  pop();
  
  push();
  translate(300, -100, 0);
  rotateX(angle);
  rotateY(angle);
  torus(50, 50);
  pop();
  
  push();
  translate(-300, 100, 0);
  rotateX(angle);
  rotateY(angle);
  cylinder(50, 50);
  pop();

  push();
  translate(300, 100, 0);
  rotateX(angle);
  rotateY(angle);
  directionalLight(255, 0, 0, 1, 0, 0);
  sphere(100, 20, 20);
  pop();

  translate(0, 100, 0);
  rotateX(angle);
  rotateY(angle);
  directionalLight(255, 0, 0, 1, 0, 0);
  cone(100, 100, 20, 20);
  pop();
  angle += 1;
}
