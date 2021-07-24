function setup() {
  createCanvas(900, 600, WEBGL);
  angleMode(DEGREES);
}

function draw() {
  background(125);

  // sun
  sphere(100, 10, 10);
  pointLight(255, 255, 255, 0, 0, 0);
  pointLight(255, 255, 255, 0, 0, 0);
  
  // earth
  translate( cos(frameCount) * 300, 0, sin(frameCount) * 300);
  rotateY(frameCount);
  ambientMaterial(255);
  sphere(50, 10, 10);

  // camera
  camera(0, -500, 800);
}
