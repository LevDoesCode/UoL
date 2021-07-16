function setup()
{
  createCanvas(500, 500);
  background(0);
  angleMode(DEGREES);
}

function draw()
{ 
  translate(width/2, height/2);
  let theta = frameCount;
  let radius = frameCount/10;
  
  let x = cos(theta) * radius;
  let y = sin(theta) * radius;
  //let x = cos(radians(theta)) * radius;
  //let y = sin(radians(theta)) * radius;
  fill(255);
  noStroke();
  ellipse(x, y, 15, 15);
}
