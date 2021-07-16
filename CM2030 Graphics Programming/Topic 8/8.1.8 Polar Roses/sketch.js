function setup()
{
  createCanvas(500, 500);
  background(0);
}

function draw()
{
  background(0);
  translate(width/2, height/2);

  for (let angle=0; angle < TWO_PI; angle += 0.1)
  {
    let r = 100;
    let x = r * cos(angle);
    let y = r * sin(angle);
    stroke(255);
    strokeWeight(4);
    point(x, y);
  }
}