let color1 = 0;

function setup() {
  createCanvas(720, 400);
  colorMode(HSB);
  noStroke();
  rectMode(CENTER);
}

function draw() {

  // complementary colors
  background(0);
  fill(0, 100, 100);
  rect(120, 120, 200, 200);
  fill(180, 100, 100);
  rect(120, 120, 100, 100);

  // triatic colors
  let startColor = 0;
  let colorDiff = 360/3;
  fill(startColor, 100, 100);
  rect(340, 120, 200, 200);
  fill(startColor + colorDiff, 100, 100);
  rect(340, 120, 150, 150);
  fill(startColor + colorDiff * 2, 100, 100);
  rect(340, 120, 100, 100);

  //if(frameCount % 10 == 0)
  color1 + 1 == 360 ? color1 = 0 : color1 += 1;
  //startColor = 40;
  fill(color1, 100, 100);
  rect(560, 120, 200, 200);
  fill(color1 + colorDiff, 100, 100);
  rect(560, 120, 150, 150);
  fill(color1 + colorDiff * 2, 100, 100);
  rect(560, 120, 100, 100);
}