let font;
let max;

function preload() {
  font = loadFont('assets/Calistoga-Regular.ttf');
}

let points;

function setup() {
  createCanvas(900, 400);
  fill(255, 104, 204, 150);
  noStroke();

  points = font.textToPoints('c o d e', 50, 300, 300, {
    sampleFactor: .3,
    simplifyThreshold: 0
  });
  max = 20;
}

function draw() {
    background(0);

    for (let i = 0; i < points.length; i++) {
      let xmap = map(mouseX, 0, width, 0, max);
      let ymap = map(mouseX, 0, width, 0, max);
      let deltaX = random(-xmap, xmap);
      let deltaY = random(-ymap, ymap);
      ellipse(points[i].x + deltaX, points[i].y + deltaY, 10, 10);
    }
    noLoop();
}

function mouseMoved(){
    loop();
}
