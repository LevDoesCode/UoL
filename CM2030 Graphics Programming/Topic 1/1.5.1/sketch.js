let state = false;
let locX = 200;
let locY = 200;
let w = 200;
let h = 100;
let myButton = null;

function setup() {
    createCanvas(900, 600);
    myButton = new Button(200, 200, 200, 100);
}

function draw()
{
    background(220);
    myButton.draw();

}

function mousePressed()
{
    myButton.flick(mouseX, mouseY);
}

class Button
{
    constructor(x, y, w, h)
    {
        this.state = false;
        this.locX = x;
        this.locY = y;
        this.w = w;
        this.h = h;
    }
    draw()
    {
        if(this.state == true) fill (255);
        else fill(0);
        rect(locX, locY, w, h);
    }
    flick(x, y)
    {
        if(x > this.locX && x < this.locX + this.w && y > this.locY && y < this.locY + this.h)
            this.state = !this.state;
    }
}