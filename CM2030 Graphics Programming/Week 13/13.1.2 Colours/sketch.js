function setup() {
  createCanvas(1000, 500);
  colorMode(RGB);
  for(let i=0; i<255; i++)
  {
    for(let j=0; j<255; j++)
    {
      stroke(i, j, 0);
      point(i, j);
    }
  }

  colorMode(HSB);
  translate(255, 0);
  for(let x=0; x<360; x++)
  {
    for(let y=0; y<100; y++)
    {
      stroke(x, y, 100);
      point(x, y);
    }
  }

  translate(0, 155);
  for(let x=0; x<360; x++)
  {
    for(let y=0; y<100; y++)
    {
      stroke(x, 100, y);
      point(x, y);
    }
  }

  noLoop();
}

function draw() {

}