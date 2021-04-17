function setup() {
    createCanvas(900, 600);
    background(0);
}

function draw()
{
    background(220);

    fill(0);
    rect(200, 100, 100, 100);

    fill(125);
    push();
    rotate(radians(45));
    translate(200, 100);
    rect(0, 0, 100, 100);
    pop();

    push();
    translate(200, 100);
    rotate(radians(45));
    rect(0, 0, 100, 100);
    pop();

    push();
    rectMode(CENTER);
    translate(200 + 100/2, 100 + 100/2);
    rotate(radians(45));
    rect(0, 0, 100, 100);
    pop();

    push();
    rectMode(CENTER);
    translate(200 + 100/2, 100 + 100/2);
    rotate(radians(45));
    fill('blue');
    scale(0.5, 0.5);
    rect(0, 0, 100, 100);
    pop();
}
