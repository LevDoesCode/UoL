let time = 0;

function setup() {
    createCanvas(900, 600);
    background(0);
    rectMode(CENTER);
}

function draw() {
    background(0);

    let nX = noise(time);
    let locX = map(nX, 0, 1, 0, width);
    let nY = noise(time + 5);
    let locY = map(nY, 0, 1, 0, height);
    translate(locX, locY);
    


    rotZ = map(nX, 0, 1, -25, 25);
    rotate(rotZ);
    let color = map(nX, 0, 1, 0, 150);
    fill(color, 0, 0);
    rect(0, 0, 150, 150);
    time+=0.01;
}
