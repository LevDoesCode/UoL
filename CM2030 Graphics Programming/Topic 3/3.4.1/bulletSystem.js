class BulletSystem {
  constructor() {
    this.bullets = [];
    this.velocity = new createVector(0, -5);
    this.diam = 10;
  }

  run() {
    this.move();
    this.draw();
    this.edges();
  }

  fire(x, y) {
    this.bullets.push(createVector(x, y));
  }

  //draws all bullets
  draw() {
    fill(255);
    for (var i = 0; i < this.bullets.length; i++) {
      ellipse(this.bullets[i].x, this.bullets[i].y, this.diam, this.diam);
    }
  }

  //updates the location of all bullets
  move() {
    for (var i = 0; i < this.bullets.length; i++) {
      this.bullets[i].y += this.velocity.y;
    }
  }

  removeBullet(index) {
    if (this.bullets.length <= 0 || index < 0 || index >= this.bullets.length)
      return;
    this.bullets.splice(index, 1);
  }

  //check if bullets leave the screen and remove them from the array
  edges() {
    // YOUR CODE HERE (3 lines approx)
    let leftBound = 0;
    let rightBound = width;
    let topBound = 0;
    let botBound = height;

    for (let i = 0; i < this.bullets.length; i++) {
      let bullet = this.bullets[i];
      if (
        bullet.y + this.diam < topBound ||
        bullet.y - this.diam > botBound ||
        bullet.x - this.diam > rightBound ||
        bullet.x + this.diam < leftBound
      )
        this.removeBullet(i);
    }
  }
}
