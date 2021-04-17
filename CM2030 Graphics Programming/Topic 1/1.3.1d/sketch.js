function setup() {
    createCanvas(720, 400);
    rectMode(CENTER);
}

function draw()
{
    background(220);
    fill(0);

    translate(200, 200);
    rotate(radians(45));
    rect(0, 0, 200, 200);
    
    fill('red');

    push()
    translate(100, 100);
    ellipse(0, 0, 30, 30);
    pop();

    push();
    translate(-100, -100);
    ellipse(0, 0, 30, 30);
    pop();

    push();
    translate(100, -100);
    ellipse(0, 0, 30, 30);
    pop();

    push();
    translate(-100, 100);
    ellipse(0, 0, 30, 30);
    pop();
}
