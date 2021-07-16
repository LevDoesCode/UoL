let n = 6;
let d = 71;
let sliderd;
let slidern;

function setup()
{
  createCanvas(500, 500);
  angleMode(DEGREES);
  sliderd = createSlider(1, 180, 1);
  slidern = createSlider(1, 180, 1);
  //sliderd.input(draw);
  background(0);
}

function draw()
{
  background(0);
  translate(width/2, height/2);
  stroke(255);
  noFill(); 
  strokeWeight(1);
  d = sliderd.value();
  n = slidern.value();

  beginShape();
  for(let i = 0; i <= 360; i++)
  {
    let k = i * d;
    let r = 200 * sin(n*k);
    let x = r * cos(k);
    let y = r * sin(k);
    vertex(x, y);
  }
  endShape();

  noFill();
  stroke(255, 0, 255);
  strokeWeight(4);
  beginShape();
  for(let i = 0; i <= 360; i++)
  {
    let k = i;
    let r = 200 * sin(n*k);
    let x = r * cos(k);
    let y = r * sin(k);
    vertex(x, y);
  }
  endShape();
  //noLoop();
}