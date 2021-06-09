var spaceship;
var asteroids;
var atmosphereLoc;
var atmosphereSize;
var earthLoc;
var earthSize;
var starLocs = [];
var playing;
var sizeL;
var sizeS;
var myCount;
var maxLives;

//////////////////////////////////////////////////
function setup() {
  createCanvas(1200, 800);
  maxLives = 4;
  spaceship = new Spaceship(maxLives);
  asteroids = new AsteroidSystem();

  //location and size of earth and its atmosphere
  atmosphereLoc = new createVector(width / 2, height * 2.9);
  atmosphereSize = new createVector(width * 3, width * 3);
  earthLoc = new createVector(width / 2, height * 3.1);
  earthSize = new createVector(width * 3, width * 3);
  playing = true;

  //graphical variables
  sizeL = 50;
  sizeS = 30;
  myCount = 0;
}

//////////////////////////////////////////////////
function draw() {
  background(0);
  sky();

  spaceship.run();
  asteroids.run(myCount/1000); // To increase the asteroid spawning rate

  drawEarth();

  checkCollisions(spaceship, asteroids); // function that checks collision between various elements

  drawGUI();
  myCount += 1;
}

//////////////////////////////////////////////////
// GUI
function drawGUI()
{
  // draw score
  fill(0, 255, 0);
  textAlign(LEFT);
  textSize(sizeS);
  text("Score: " + spaceship.score, 20, sizeS);

  // draw player lives
  fill(0, 255, 0);
  for (let i = 0; i < spaceship.lives; i++) {
    let locationX = width - spaceship.size - i * spaceship.size * 1.2;
    let locationY = sizeS;
    triangle(
      locationX - spaceship.size/2, locationY + spaceship.size/2,
      locationX + spaceship.size/2, locationY + spaceship.size/2,
      locationX, locationY - spaceship.size/2
    );
  }

  if(!playing)
  {
    fill(255);
    textSize(80);
    textAlign(CENTER);
    if(spaceship.lives > 0)
    {
      textSize(sizeL);
      text("You lost a life!", width / 2, height / 2);
      textSize(sizeS);
      text("press SPACE to continue", width / 2, height / 2 + sizeL);
    }
    else
    {
      textSize(sizeL);
      text("GAME OVER", width / 2, height / 2);
      textSize(sizeS);
      text("press SPACE to restart", width / 2, height / 2 + sizeL);
    }
  }
}

//////////////////////////////////////////////////
//draws earth and atmosphere
function drawEarth() {
  noStroke();
  //draw atmosphere
  fill(0, 0, 255, 50);
  ellipse(atmosphereLoc.x, atmosphereLoc.y, atmosphereSize.x, atmosphereSize.y);
  //draw earth
  fill(100, 255);
  ellipse(earthLoc.x, earthLoc.y, earthSize.x, earthSize.y);
}

//////////////////////////////////////////////////
//checks collisions between all types of bodies
function checkCollisions(spaceship, asteroids) {
  //spaceship-2-asteroid collisions
  //YOUR CODE HERE (2-3 lines approx)
  for (let i = 0; i < asteroids.locations.length; i++) {
    if (
      isInside(
        spaceship.location,
        spaceship.size / 2,
        asteroids.locations[i],
        asteroids.diams[i] / 2
      )
    )
      gameOver();
  }
  //asteroid-2-earth collisions
  //YOUR CODE HERE (2-3 lines approx)
  for (let i = 0; i < asteroids.locations.length; i++) {
    if (
      isInside(
        earthLoc,
        earthSize.y / 2,
        asteroids.locations[i],
        asteroids.diams[i] / 2
      )
    )
      gameOver();
  }
  //spaceship-2-earth
  //YOUR CODE HERE (1-2 lines approx)
  if (
    isInside(earthLoc, earthSize.y / 2, spaceship.location, spaceship.size / 2)
  )
    gameOver();
  //spaceship-2-atmosphere
  //YOUR CODE HERE (1-2 lines approx)
  if (
    isInside(
      atmosphereLoc,
      atmosphereSize.y / 2,
      spaceship.location,
      spaceship.size / 2
    )
  )
    spaceship.setNearEarth();
  //bullet collisions
  //YOUR CODE HERE (3-4 lines approx)
  for (let i = 0; i < spaceship.bulletSys.bullets.length; i++) {
    for (let j = 0; j < asteroids.locations.length; j++) {
      if (
        isInside(
          spaceship.bulletSys.bullets[i],
          spaceship.bulletSys.diam,
          asteroids.locations[j],
          asteroids.diams[j] / 2
        )
      ) {
        asteroids.destroy(j);
        spaceship.score += 10;
      }
    }
  }
}

//////////////////////////////////////////////////
//helper function checking if there's collision between object A and object B
function isInside(locA, sizeA, locB, sizeB) {
  // YOUR CODE HERE (3-5 lines approx)
  if (dist(locA.x, locA.y, locB.x, locB.y) > sizeA + sizeB) return false;
  return true;
}

//////////////////////////////////////////////////
function keyPressed() {
  if(keyIsPressed && keyCode === 32) //spacebar
  {
    if(playing) //mid game, should shoot a bullet
    {
      spaceship.fire();
    }
    else //game stopped
    {
      if(spaceship.lives > 0) //has or more lives
      {
        continueGame();
      }
      else //no more lives left
      {
        restartGame();
      }
    }
  }
  //console.log(spaceship.bulletSys.bullets.length);
}

//////////////////////////////////////////////////
// function that ends the game by stopping the loops and displaying "Game Over"
function gameOver() {
  spaceship.die();
  playing = false;
  myCount = 0;
  noLoop();
}

function continueGame()
{
  asteroids.locations = [];
  asteroids.velocities = [];
  asteroids.accelerations = [];
  asteroids.diams = [];
  spaceship.respawn();
  playing = true;
  loop();
}

function restartGame()
{
  continueGame();
  spaceship.lives = maxLives;
  spaceship.score = 0;
}


//////////////////////////////////////////////////
// function that creates a star lit sky
function sky() {
  push();
  while (starLocs.length < 300) {
    starLocs.push(new createVector(random(width), random(height)));
  }
  fill(255);
  for (var i = 0; i < starLocs.length; i++) {
    rect(starLocs[i].x, starLocs[i].y, 2, 2);
  }

  if (random(1) < 0.3) starLocs.splice(int(random(starLocs.length)), 1);
  pop();
}
