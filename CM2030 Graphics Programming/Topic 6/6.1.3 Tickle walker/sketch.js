let x;
let y;
let size;

function setup() {
    createCanvas(900, 600);
    background(0);
    x = width/2;
    y = height/2;
    size = 30;
}

function draw()
{
    background(0);
    fill(255);
    ellipse(x, y, size, size);
    if(mouseIsPressed & dist(x, y, mouseX, mouseY) < size/2)
        randomIt();
}

function randomIt()
{
    let min = 1;
    let max = 2;
    if(random(1)>0.5)
    {
        x += random(min, max);
    }
    else
    {
        x -= random(min, max);
    }
    if(random(1)>0.5)
    {
        y += random(min, max);
    }
    else
    {
        y -= random(min, max);
    }
}