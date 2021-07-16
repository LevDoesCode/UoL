let d = 8
let n = 5;
let sliderk;

function setup()
{
  createCanvas(500, 500);
  angleMode(DEGREES);
  sliderd = createSlider(1, 10, 5);
  slidern = createSlider(1, 10, 5);
  background(0);
}

function draw()
{
  background(0);
  translate(width/2, height/2);
  stroke(255);
  noFill();

  beginShape();
  for(let a = 0; a < 360; a++)
  {
    let r = 150;
    let x = r * cos(a);
    let y = r * sin(a);
    vertex(x, y);
  }
  endShape(CLOSE);
}