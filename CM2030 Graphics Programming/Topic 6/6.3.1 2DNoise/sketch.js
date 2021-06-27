//////////////////////////////////////////////////
// COURSERA GRAPHICS PROGRAMMING
//////////////////////////////////////////////////
function setup() {
    createCanvas(200, 200);
    background(0);
    rectMode(CENTER);
}
//////////////////////////////////////////////////
function draw() {
    background(0);

    //randomGrid();

    noiseDetail(map(mouseY, 0, height, 0, 5));
    noisyGrid();
}
///////////////////////////////////////////////////
function randomGrid(){
    for (var x=0; x<width; x+=1){
        for (var y=0; y<height; y+=1){
            var c = random(0, 255);
            stroke(c)
            point(x, y);
        }
    }
    noLoop();
}
///////////////////////////////////////////////////
function noisyGrid(){
    for (var x=0; x<width; x+=1){
        for (var y=0; y<height; y+=1){
            var n = noise(map(mouseX, 0, width, x/10, x/100), map(mouseX, 0, width, y/10, y/100));
            var c = map(n, 0, 1, 0, 255);
            stroke(c)
            point(x, y);
        }
    }
}
