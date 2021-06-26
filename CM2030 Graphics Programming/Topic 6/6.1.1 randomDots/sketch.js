////////////////////////////////////
// COURSERA GRAPHICS PROGRAMMING
////////////////////////////////////
function setup() {
    createCanvas(900, 600);
    background(0);
    randomSeed(0);
}
//////////////////////////////////////////
function draw() {
    var randX = random(0, width);
    var randY = random(0, height);

    fill(random(50, 255), random(50, 255), random(50, 255), random(255));
    noStroke();
    let size = random(15, 25);
    ellipse(randX, randY, size, size);
}
