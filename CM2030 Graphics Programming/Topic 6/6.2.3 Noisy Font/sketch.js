let points;
let font;
let time = 0;
let amt = 20;
function preload() {
  font = loadFont('assets/Calistoga-Regular.ttf');
}

function setup() {
  createCanvas(900, 400);
  background(0);

  points = font.textToPoints('c o d e', 50, 300, 300, {
    sampleFactor: .3,
    simplifyThreshold: 0
  });
}

function draw() {
  background(0);
  noStroke();
  fill(255, 104, 204, 150);

  amt = map(mouseX, 0, width, 0, 20);
  // **** Your code here ****
  for (let i = 0; i < points.length; i++)
  {
    let nX = noise(frameCount%width + points[i].x);
    let deltaX = map(nX, 0, 1, -amt, amt);
    
    let nY = noise(frameCount%width + points[i].y);
    let deltaY = map(nY, 0, 1, -amt, amt);
    //console.log(nX);
    ellipse(points[i].x + deltaX, points[i].y + deltaY, 10, 10);
  }
}
