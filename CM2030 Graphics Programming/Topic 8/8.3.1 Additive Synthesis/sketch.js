function setup()
{
  createCanvas(900, 600);
  angleMode(DEGREES);
}

function draw()
{
  background(0);
  translate(0, height/2);
  
  stroke(255);
  noFill();
  
  beginShape();
  for (var x = 0; x <= width; ++x)
  {
    let wave1 = sin(x + frameCount) * height/4;
    let wave2 = sin(x * 10 + frameCount) * height/20;
    let wave3 = noise(x/10 + frameCount/100) * 150;
    vertex(x, wave3 + wave2 + wave1);
  }
  endShape();
}