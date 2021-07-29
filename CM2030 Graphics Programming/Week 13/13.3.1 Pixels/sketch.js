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
    rect(mouseX, mouseY, 50, 50);

    // getting color values manually
    img.loadPixels();  // make the pixel array ready to be used with img.pixels[]
    let index = (img.width * mouseY + mouseX) * 4; //index of first value
    let channelRed = img.pixels[index + 0];
    let channelGrn = img.pixels[index + 1];
    let channelBlu = img.pixels[index + 2];
    let channelAlp = img.pixels[index + 3];

    fill('rgba(' + channelRed + ',' + channelGrn + ',' + channelBlu + ',' + channelAlp + ')');
    //fill(channelRed, channelGrn, channelBlu, channelAlp);
    rect(mouseX + 50, mouseY, 50, 50);

}
