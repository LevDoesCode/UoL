let n = 6;
let d = 71;
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
  for(let i = 0; i <= 360; i++)
  {
    let k = i * d;
    let r = 200 * sin(n*k);
    let x = r * cos(k);
    let y = r * sin(k);
    vertex(x, y);
  }
  endShape(CLOSE);
}