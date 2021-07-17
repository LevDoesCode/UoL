let startSize;
let functionCalls = 0;
function setup()
{
  createCanvas(900, 900);
  background(0);

  fill('white');
  noStroke();
  noSmooth();
  rectMode(CENTER);
  startSize = Math.pow(3, 6); // 3 * 3 * 3 * 3 * 3 * 3
  console.log(startSize);
};

function draw()
{
  translate(width/2, height/2);
  carpet(startSize);
  noLoop();
};

function carpet(side)
{
  functionCalls++;
  side = side / 3;
  
  if(side >= 1)
  {
    rect(0, 0, side, side);

    // WW
    push();
    translate(-side, 0);
    carpet(side);
    pop();

    // NW
    push();
    translate(-side, -side);
    carpet(side);
    pop();

    // NN
    push();
    translate(0, -side);
    carpet(side);
    pop();

    // NE
    push();
    translate(side, -side);
    carpet(side);
    pop();

    // EE
    push();
    translate(side, 0);
    carpet(side);
    pop();

    // SE
    push();
    translate(side, side);
    carpet(side);
    pop();

    // SS
    push();
    translate(0, side);
    carpet(side);
    pop();

    // SW
    push();
    translate(-side, side);
    carpet(side);
    pop();
  }
};
