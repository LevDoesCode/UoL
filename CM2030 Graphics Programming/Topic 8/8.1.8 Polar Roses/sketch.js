function setup()
{
  createCanvas(500, 500);
  background(0);
}

function draw()
{
  background(0);
  translate(width/2, height/2);

  stroke(255);
  noStroke();

  beginShape();
  for (let angle=0; angle < TWO_PI; angle += 0.02)
  {
    let r = 200 * cos(7 * angle);
    let x = r * cos(angle);
    let y = r * sin(angle);
    
    vertex(x, y);
  }
  endShape(CLOSE);
}