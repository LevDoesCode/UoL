////////////////////////////////////////////////////////////////
function setupGround() {
  ground = Bodies.rectangle(500, 600, 1000, 40, {
    isStatic: true,
    angle: 0,
  });
  World.add(engine.world, [ground]);
}

////////////////////////////////////////////////////////////////
function drawGround() {
  push();
  fill(128);
  drawVertices(ground.vertices);
  pop();
}

////////////////////////////////////////////////////////////////
function setupPropeller() {
  // your code here
  propeller = Bodies.rectangle(150, 480, 200, 15, { isStatic: true, angle: 0 });
  World.add(engine.world, [propeller]);
}

////////////////////////////////////////////////////////////////
//updates and draws the propeller
function drawPropeller() {
  Body.setAngle(propeller, angle);
  Body.setAngularVelocity(propeller, angleSpeed);
  push();
  fill(255);
  drawVertices(propeller.vertices);
  pop();
  angle += angleSpeed;
}

////////////////////////////////////////////////////////////////
function setupBird() {
  var bird = Bodies.circle(mouseX, mouseY, 20, {
    friction: 0,
    restitution: 0.95,
  });
  Matter.Body.setMass(bird, bird.mass * 10);
  World.add(engine.world, [bird]);

  pinkFrame.push(Math.trunc(random(1, 5)) - 1);
  birds.push(bird);
}

////////////////////////////////////////////////////////////////
function setupGreenBird() {
  if(greenCount == 0)
    return;
  var greenBird = Bodies.circle(200, 250, 60, {
    friction: 0,
    restitution: 0.95
  });

  slingshotConstraint = Constraint.create({
    bodyB: greenBird,
    pointA: { x: 200, y: 200 },
    pointB: { x: 0, y: 0 },
    stiffness: 0.01,
    damping: 0.0001,
  });

  Matter.Body.setMass(greenBird, greenBird.mass * 10);
  World.add(engine.world, [greenBird, slingshotConstraint]);

  greenFrame.push(Math.trunc(random(1, 5)) - 1);
  greenBirds.push(greenBird);
  greenCount--;
}
////////////////////////////////////////////////////////////////
function drawBirds() {
  fill("orange");
  for (let i = 0; i < birds.length; i++) {
    //drawVertices(birds[i].vertices);
    //replaced with image

    push();
    imageMode(CENTER);
    translate(birds[i].position.x, birds[i].position.y);
    rotate(birds[i].angle);
    image(pinkSprite[pinkFrame[i]], 0, 0, 40, 40);
    pop();
    if (frameCount % 5 == 0)
      pinkFrame[i] < 3 ? pinkFrame[i]++ : (pinkFrame[i] = 0);

    if (isOffScreen(birds[i])) {
      World.remove(engine.world, birds[i]);
      birds.splice(i, 1);
      pinkFrame.splice(i, 1);
      i--;
    }
  }
}

////////////////////////////////////////////////////////////////
function drawGreenBirds() {
  fill("green");
  for (let i = 0; i < greenBirds.length; i++) {
    push();
    imageMode(CENTER);
    translate(greenBirds[i].position.x, greenBirds[i].position.y);
    rotate(greenBirds[i].angle);
    image(greenSprite[greenFrame[i]], 0, 0, 120, 120);
    pop();
    if (frameCount % 5 == 0)
      greenFrame[i] < 3 ? greenFrame[i]++ : (greenFrame[i] = 0);

    if (isOffScreen(greenBirds[i])) {
      World.remove(engine.world, greenBirds[i]);
      greenBirds.splice(i, 1);
      greenFrame.splice(i, 1);
      i--;
    }
  }
}



////////////////////////////////////////////////////////////////
//creates a tower of boxes
function setupTower() {
  boxes = Composites.stack(500, 100, 3, 6, 0, 0, function (x, y) {
    let partA = Bodies.rectangle(x, y, 80, 80, { density: 0.001 });
    colors.push(Math.trunc(random(100, 255)));
    return Body.create({ parts: [partA] });
  });
  Composite.add(engine.world, [boxes]);
}
////////////////////////////////////////////////////////////////
//draws tower of boxes
function drawTower() {
  push();
  for (let i = 0; i < boxes.bodies.length; i++) {
    fill(0, colors[i], 0);
    noStroke();
    drawVertices(boxes.bodies[i].vertices);
    if (isOffScreen(boxes.bodies[i])) {
      World.remove(engine.world, boxes.bodies[i]);
      boxes.bodies.splice(i, 1);
      colors.splice(i, 1);
      i--;
    }
  }
  pop();
}
////////////////////////////////////////////////////////////////
function setupSlingshot() {
  slingshotBird = Bodies.circle(200, 250, 20, {
    friction: 0,
    restitution: 0.95,
  });

  slingshotConstraint = Constraint.create({
    bodyB: slingshotBird,
    pointA: { x: 200, y: 200 },
    pointB: { x: 0, y: 0 },
    stiffness: 0.01,
    damping: 0.0001,
  });
  Matter.Body.setMass(slingshotBird, slingshotBird.mass * 10);
  World.add(engine.world, [slingshotBird, slingshotConstraint]);

  redFrame.push(Math.trunc(random(1, 5)) - 1);
  slingshotBirds.push(slingshotBird);
}
////////////////////////////////////////////////////////////////
//draws slingshot bird and its constraint
function drawSlingshot() {
  fill("red");
  for (let i = 0; i < slingshotBirds.length; i++) {
    //drawVertices(slingshotBirds[i].vertices); 
    //replaced with image

    push();
    imageMode(CENTER);
    translate(slingshotBirds[i].position.x, slingshotBirds[i].position.y);
    rotate(slingshotBirds[i].angle);
    image(redSprite[redFrame[i]], 0, 0, 40, 40);

    if (frameCount % 5 == 0)
      redFrame[i] < 3 ? redFrame[i]++ : (redFrame[i] = 0);

    if (isOffScreen(slingshotBirds[i])) {
      World.remove(engine.world, slingshotBirds[i]);
      slingshotBirds.splice(i, 1);
      i--;
    }
    pop();
  }
  drawConstraint(slingshotConstraint);
}
/////////////////////////////////////////////////////////////////
function setupMouseInteraction() {
  var mouse = Mouse.create(canvas.elt);
  var mouseParams = {
    mouse: mouse,
    constraint: { stiffness: 0.05 },
  };
  mouseConstraint = MouseConstraint.create(engine, mouseParams);
  mouseConstraint.mouse.pixelRatio = pixelDensity();
  World.add(engine.world, mouseConstraint);
}
