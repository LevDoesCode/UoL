function setup() {
    createCanvas(900, 600);
    background(0);
}

function draw()
{
    background(125);

    var mouse = createVector(mouseX, mouseY);
    var center = createVector(width/2, height/2);

    mouse.sub(center);

    textSize(20);
    // We use extract the magnitude of a vector using the p5.js .mag() function
    text("Magnitude: " + mouse.mag().toFixed(2), 0,  20);

    fill('white');
    rect(0, 30, mouse.mag(), 10);
    console.log(typeof mouse.mag())

    translate(width/2, height/2);
    strokeWeight(3);

    line(0,0, mouse.x, mouse.y);
}
