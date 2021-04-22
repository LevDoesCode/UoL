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

    let normal = mouse.copy();

    textSize(20);
    text("Normal: " + normal.normalize(), 20, 50);

    // We extract the direction of a vector using the p5.js .normalize() function
    normal = normal.mult(50);
    line(10, 60, 10 + normal.x, 60 + normal.y);    

    fill('white');
    console.log(typeof normal);

    // Center line
    translate(width/2, height/2);
    strokeWeight(3);

    line(0,0, mouse.x, mouse.y);
}
