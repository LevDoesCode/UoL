let ball;

function setup()
{
  createCanvas(900, 600);
  ball = new Ball();
  background(0);
}

function draw()
{
  
  ball.run();
}

class Ball
{
  constructor()
  {
    this.velocity = new createVector(0, 0);
    this.location = new createVector(width/2, height/2);
    this.prevLocation = new createVector(width/2, height/2); 
    this.acceleration = new createVector(0, 0);
    this.maxVelocity = 5;
  }

  run()
  {
    this.draw();
    this.move();
  }

  draw()
  {
    fill(125);
    //ellipse(this.location.x, this.location.y, 40, 40);
    stroke(255);
    strokeWeight(3);
    line(this.location.x, this.location.y, this.prevLocation.x, this.prevLocation.y);
    this.prevLocation = this.location.copy();
  }

  move()
  {
    let mouse = createVector(mouseX, mouseY);
    let dir = p5.Vector.sub(mouse, this.location);
    console.log(dir);
    dir.normalize();
    dir.mult(.5); // could be any number
    this.acceleration = dir;

    this.velocity.add(this.acceleration);
    this.velocity.limit(this.maxVelocity);
    this.location.add(this.velocity);
  }
}
