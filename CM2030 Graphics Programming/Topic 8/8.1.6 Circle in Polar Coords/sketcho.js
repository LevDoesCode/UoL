function setup()
{
  createCanvas(500, 500);
  angleMode(DEGREES);
}

function draw()
{
  background(0);
  translate(width/2, height/2);
  let radius = 200;
  fill(255);

  for(let theta=0; theta < 360; theta += 20)
  {
    let x = cos(theta) * radius;
    let y = sin(theta) * radius;
    //let x = cos(radians(theta)) * radius;
    //let y = sin(radians(theta)) * radius;
    ellipse(x, y, 15, 15);
  }
}
