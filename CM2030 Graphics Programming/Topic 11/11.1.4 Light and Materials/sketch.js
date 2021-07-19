function setup() {
  createCanvas(500, 500, WEBGL);
  angleMode(DEGREES);
}

function draw() {
  background(125);
  //noStroke();
  // if(frameCount%1000 >= 100)
  // {
  //   normalMaterial();
  // }
  // if(frameCount%1000 >= 200)
  // {
  //   ambientMaterial(255, 255, 255);
  //   ambientLight(0, 255, 0);
  // }
  // if(frameCount%1000 >= 300)
  // {
  //   ambientMaterial(255, 255, 255);
  //   // first 3 params are the RGB values, then the locaction of the light
  //   pointLight(0, 255, 0, 0, -200, 100);
  //   pointLight(255, 0, 0, mouseX - width/2, mouseY - height/2, 100);
  //   pointLight(255, 0, 0, width/2 - mouseX, height/2 - mouseY, 100);
  // }
  // if(frameCount%1000 >= 400)
  // {
  //   noStroke()
  //   specularMaterial(255);
  //   pointLight(0, 255, 0, 0, -200, 100);
  //   pointLight(255, 0, 0, mouseX - width/2, mouseY - height/2, 100);
  //   pointLight(255, 0, 0, width/2 - mouseX, height/2 - mouseY, 100);
  // }
  // if(frameCount%1000 >= 500)
  // {
  //   noStroke();

  // }

  //specular light
  // noStroke()
  // specularMaterial(255);
  // pointLight(255, 0, 0, mouseX - width/2, mouseY - height/2, 100);
  // pointLight(0, 588, 0, 0, -200, 100);

  // Ambient Material
  // noStroke();
  // ambientMaterial (255);
  // pointLight(255, 0, 0, mouseX - width/2, mouseY - height/2, 100);
  // pointLight(0, 588, 0, 0, -200, 100);

  // directional light
  noStroke();
  ambientMaterial (255);
  directionalLight(255, 0, 0, 1, 0, 0);

  sphere(100, 30, 30);
}