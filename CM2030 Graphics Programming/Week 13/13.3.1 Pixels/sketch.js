let img;

function preload() {
    img = loadImage('rockets.png');
}
function setup() {
    createCanvas(640 * 2, 400);
    pixelDensity(1);
}

function draw() {
    background(150);
    image(img, 0, 0);

    // getting pixel information using get()
    let c = img.get(mouseX, mouseY);
    fill(c);
    rect(mouseX+10, mouseY+10, 50, 50);

    // getting color values manually
    loadPixels();  // make the pixel array ready to be used with img.pixels[]
    //img.loadPixels() // or we can load the pixel array form the image object instead of the canvas
    let index = (width * mouseY + mouseX) * 4; // index of first value
    // let index = (img.width * mouseY + mouseX) * 4; // calculating the width from the image object
    let channelRed = pixels[index + 0];
    // let channelRed = img.pixels[index + 0]; // or read from the image pixel array instead of the canvas
    let channelGrn = pixels[index + 1];
    let channelBlu = pixels[index + 2];
    let channelAlp = pixels[index + 3];

    
    fill(channelRed, channelGrn, channelBlu, channelAlp);
    // or
    fill('rgba(' + channelRed + ',' + channelGrn + ',' + channelBlu + ',' + channelAlp + ')');
    rect(mouseX + 10 + 50, mouseY + 10, 50, 50);
}
