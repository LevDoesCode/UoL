let video;
let strip;
let strips=[];
let scan;

function setup() {
    createCanvas(640 * 2, 480);
    pixelDensity(1);
    video = createCapture(VIDEO);
    video.hide();
    scan = createGraphics(640, 480);
}

function draw() {
    background(150);
    image(video, 0, 0);

    // STEP 1 - write your cocde below
    strip = video.get(video.width/2, 0, 1, video.height);
    // save to scan object
    scan.image(strip, frameCount%640 - 1, 0);
    // or store it in an array
    //strips[frameCount%640 - 1] = strip;

    push();
    stroke(255, 0, 0);
    line(video.width / 2, 0, video.width / 2, video.height);
    pop();

    // STEP 2 - write your code below
    // one of the two methods below will work
    
    image(scan, 640, 0);
    //for(let i=0; i<strips.length; i++)
    //    image(strips[i], 640 + i, 0);
}
