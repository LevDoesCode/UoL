function setup() {
  createCanvas(900, 600, WEBGL);
  angleMode(DEGREES);
}

function draw() {
  background(125);
  
  // camera
  let zLoc = ((sin(frameCount) + 1)/2 * height) + 200;
  // or
  zLoc = map(sin(frameCount), -1, 1, 200, 600);
  // using noise
  xLoc = map(noise(frameCount/200), 0, 1, -500, 500);
  yLoc = map(noise(frameCount/200 + 100), 0, 1, -500, 500);
  zLoc = map(noise(frameCount/200 + 150), 0, 1, 300, 800);
  // to rotate
  xLoc = cos(frameCount) * height;
  yLoc = sin(frameCount) * 300;
  zLoc = sin(frameCount) * height;
  // camera location x, y, z | Pointing to x, y, z | Orientation(tilt) x,y,z
  camera(xLoc, yLoc, zLoc, 0, 0, 0, 0, 1, 0);

  // objects
  normalMaterial();
  torus(200, 50, 50, 50);
  
  translate(0, 100, 0);
  rotateX(90);
  fill(200);
  plane(500, 500);
}
