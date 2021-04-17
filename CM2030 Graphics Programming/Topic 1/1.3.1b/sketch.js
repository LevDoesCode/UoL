function setup() {
    createCanvas(720, 400);
}

function draw()
{
    background(0, 150, 200);
    drawCat(mouseX, mouseY);
}

function drawCat(x, y)
{
    rectMode(CENTER);
    stroke(0);
    strokeWeight(2);
    translate(x, y);
    fill(255);

    rect(0, 0, 100, 100); // face
    rect(-20, -20, 25, 10); // left eye
    rect(20, -20, 25, 10); // right eye
    rect(0, 5, 7, 25); // nose
    rect(0, 30, 30, 5); // mouth
    triangle(-50, -50, -30, -70, -10, -50);
    triangle(50, -50, 30, -70, 10, -50);
}