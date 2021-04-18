function setup() {
    createCanvas(900, 600);
    background(0);
}

function draw()
{
    background(125);

    let mouse = createVector(mouseX, mouseY);
    let center = createVector(width/2, height/2);

    mouse.sub(center);

    translate(width/2, height/2);
    strokeWeight(3);

    line(0, 0, mouse.x, mouse.y);
}
