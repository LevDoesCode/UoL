function setup()
{
  createCanvas(900, 600);
  angleMode(DEGREES);
  background(0);
}

function draw()
{
  background(0);
  translate(width/2, height/2);
  
  stroke(255);
  fill(255);
  
  let amp = width / 2;
  let period = 360;
  let phase = 0;
  let freq = 0.5;
  let yamp = height /2;
  //let x = sin(360 * frameCount/period + phase) * amp;
  let x = sin(frameCount * 6 * freq + phase) * amp;
  //let y = cos(frameCount * 6 * freq) * yamp;
  ellipse(x, 0, 30, 30);
}