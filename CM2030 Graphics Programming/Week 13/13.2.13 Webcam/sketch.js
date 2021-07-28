let video;
let canvas2;
let canvas1;
let c;
function setup() {
  canvas1 = createCanvas(640, 480);
  pixelDensity(1);
  video = createCapture(VIDEO);
  video.hide();
  canvas2 = createDiv(); canvas2.style('width', '100px'); canvas2.style('height', '100px'); canvas2.style('background-color', 'green');
  canvas2.parent(canvas1.parent());
}

function draw() {
  background(150);
  
  imageMode(CENTER);
  translate(width/2, height/2);
  scale(-1, 1, 1);
  image(video, 0, 0);

  //smaller video at mouse position
  imageMode(CENTER);
  scale(1, 1, 1);
  //image(video, -mouseX + width/2, mouseY - height/2, video.width/3, video.height/3);

  // capture pixel color at mouse position
  imageMode(CORNER);
  c = video.get(video.width - mouseX, mouseY); // need to tweak the x axis because it's been scaled with a -1 before
  canvas2.style('background-color', 'rgb(' + c[0] + ',' + c[1] + ',' + c[2] + ')');
  console.log(mouseX);
  console.log(mouseY);
}