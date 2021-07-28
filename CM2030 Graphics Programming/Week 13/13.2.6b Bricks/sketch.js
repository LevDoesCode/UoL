let color1 = 0;

function setup() {
  createCanvas(720, 400);
  colorMode(HSB);
  noStroke();
  //stroke(0);

  let hueStart = 100;
  let variation = 5;

  let brickW = 72;
  let brickH = 40;

  for (let x=0; x<width; x+=brickW) {
    for (let y=0; y<height; y+=brickH) {
      fill(hueStart + random(-variation, variation), random(80, 100), random(80, 100));
      rect(x, y, brickW, brickH);
    }
  }
}

function draw() {
}