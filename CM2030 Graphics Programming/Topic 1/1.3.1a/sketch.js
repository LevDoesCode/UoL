function setup() {
    createCanvas(720, 400);
}

function draw()
{
    background(220);
    fill(0);

    translate(60, 60);
    rect(10, 10, 100, 100);

    ellipse(0, 0, 20, 20);
    ellipse(-60, -60, 20, 20);
}