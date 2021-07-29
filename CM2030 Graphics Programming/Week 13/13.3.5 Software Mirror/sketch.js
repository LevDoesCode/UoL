var video;

function setup() {
    createCanvas(640 * 2, 480);
    pixelDensity(1);
    video = createCapture(VIDEO);
    video.hide();
    noStroke();
    angleMode(DEGREES);
}

function draw() {
    background(0);
    image(video, 0, 0);

    video.loadPixels();

    translate(640, 0);
    var arcSize = 10;
    translate(arcSize / 2, arcSize / 2);

    for (let x=0; x<width/2; x+=arcSize) {
        for (let y=0; y<height; y+=arcSize) {

            let index = (video.width*y + x) * 4;
            let red = video.pixels[index + 0];
            let blu = video.pixels[index + 1];
            let grn = video.pixels[index + 2];

            // rgb to hsl
            let cmin = Math.min(red, blu, grn);
            let cmax = Math.max(red, blu, grn);
            let pixelBrightness = (cmin + cmax)/2;

            push();
            translate(x, y);
            var theta = map(pixelBrightness, 0, 255, 0, 360);
            rotate((180 - theta) / 2);
            arc(0, 0, arcSize, arcSize, 0, theta);
            pop();
        }
    }
}
