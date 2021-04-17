let state = false;
let locX = 200;
let locY = 200;
let w = 200;
let h = 100;

function setup() {
    createCanvas(900, 600);
}

function draw()
{
    background(220);
    if(state == true) fill (255);
    else fill(0);

    rect(locX, locY, w, h);
}

function mousePressed()
{
    if(mouseX > locX && mouseX < locX + w && mouseY > locY && mouseY < locY + h)
        state = !state;
}