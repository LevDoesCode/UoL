////////////////////////////////////////////////////////////////
function setupGround(){
  ground = Bodies.rectangle(500, 600, 1000, 40, {
    isStatic: true, angle: 0
  });
  World.add(engine.world, [ground]);
}

////////////////////////////////////////////////////////////////
function drawGround(){
  push();
  fill(128);
  drawVertices(ground.vertices);
  pop();
}
////////////////////////////////////////////////////////////////
function setupPropeller(){
  // your code here
  propeller = Bodies.rectangle(150, 480, 200, 15, {isStatic: true, angle: 0});
  World.add(engine.world, [propeller]);
}
////////////////////////////////////////////////////////////////
//updates and draws the propeller
function drawPropeller(){
  Body.setAngle(propeller, angle);
  Body.setAngularVelocity(propeller, angleSpeed);
  push();
  fill(255);
  //translate(propeller.position.x, propeller.position.y);
  //rotate(propeller.angle);
  drawVertices(propeller.vertices);
  pop();
  angle += angleSpeed;
}
////////////////////////////////////////////////////////////////
function setupBird(){
  var bird = Bodies.circle(mouseX, mouseY, 20, {friction: 0,
      restitution: 0.95 });
  Matter.Body.setMass(bird, bird.mass*10);
  World.add(engine.world, [bird]);
  birds.push(bird);
}
////////////////////////////////////////////////////////////////
function drawBirds(){
  push();
  for (let i = 0; i < birds.length; i++)
  {
    drawVertices(birds[i].vertices);
    if(isOffScreen(birds[i]))
    {
      World.remove(engine.world, birds[i]);
      birds.splice(i, 1);
      i--;
    }
  }
  pop();
  console.log("# Birds: ", birds.length);
  console.log("# World Bodies: ", engine.world.bodies.length);
}
////////////////////////////////////////////////////////////////
//creates a tower of boxes
function setupTower(){
  boxes = Composites.stack(500, 100, 3, 6, 0, 0,
    function(x,y){
      let partA = Bodies.rectangle(x, y, 80, 80, {density: 0.001});
      colors.push(Math.trunc(random(100, 255)));
      return Body.create({parts: [partA]});
    });
  Composite.add(engine.world, [boxes]);
}
////////////////////////////////////////////////////////////////
//draws tower of boxes
function drawTower(){
  push();
  for (let i = 0; i < boxes.bodies.length; i++) {
    fill(0, colors[i], 0);
    noStroke();
    drawVertices(boxes.bodies[i].vertices);
    if(isOffScreen(boxes.bodies[i]))
    {
      World.remove(engine.world, boxes.bodies[i]);
      boxes.bodies.splice(i, 1);
      colors.splice(i, 1);
      i--;
    }
  }
  pop();
}
////////////////////////////////////////////////////////////////
function setupSlingshot(){
//your code here
}
////////////////////////////////////////////////////////////////
//draws slingshot bird and its constraint
function drawSlingshot(){
  push();
  // your code here
  pop();
}
/////////////////////////////////////////////////////////////////
function setupMouseInteraction(){
  var mouse = Mouse.create(canvas.elt);
  var mouseParams = {
    mouse: mouse,
    constraint: { stiffness: 0.05 }
  }
  mouseConstraint = MouseConstraint.create(engine, mouseParams);
  mouseConstraint.mouse.pixelRatio = pixelDensity();
  World.add(engine.world, mouseConstraint);
}
