let d = 8
let n = 5;
let sliderk;

function setup()
{
  createCanvas(500, 500);
  sliderd = createSlider(1, 10, 5);
  slidern = createSlider(1, 10, 5)
  background(0);
}

function draw()
{
  background(0);
  translate(width/2, height/2);

  stroke(255);
  stroke(255);
  noFill();

  n = slidern.value();
  d = sliderd.value();
  k = n/d;

  beginShape();
  for (let angle=0; angle < TWO_PI * 10; angle += 0.02)
  {
    let r = 200 * cos(k * angle);
    let x = r * cos(angle);
    let y = r * sin(angle);
    
    vertex(x, y);
  }
  endShape();
}