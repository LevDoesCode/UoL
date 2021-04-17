let secLength = 160;
let secWidth = 1;
let minLength = 140;
let minWidth = 3;
let hourLength = 90;
let hourWidth = 5; 

function setup()
{
    createCanvas(900, 600);
    background(0);
}

function draw()
{
    background(255);
    noFill();
    translate(width/2, height/2);
    ellipse(0, 0, 350, 350);

    push();
    strokeWeight(secWidth);
    stroke(200, 0, 0);
    let secAngle = map(second(), 0, 60, 0, 360);
    rotate(radians(secAngle));
    line(0, 0, 0, -secLength);
    pop();

    push();
    strokeWeight(minWidth);
    let minAngle = map(minute(), 0, 60, 0, 360);
    rotate(radians(minAngle));
    line(0, 0, 0, -minLength);
    pop();

    push();
    strokeWeight(hourWidth);
    let hourAngle = map(hour(), 0, 12, 0, 360);
    rotate(radians(hourAngle));
    line(0, 0, 0, -hourLength);

        push();
            translate(0, -hourLength);
            fill(255);
            ellipse(0, 20, 20);
        pop();
    pop();

    let hours = 12;
    let hourStep = 360 / hours;
    for(let i=0; i<hours; i++)
    {
        push();
        rotate(radians(hourStep * i));
        //translate(0,)
        line(0, -175, 0, -140);
        pop();
    }

    let minStep = 360/60;
    push()
    for(let i=0; i<60; i++)
    {
        if( i % 5 != 0 )
        {
            line(0, -175, 0, -155);
        }
        rotate(PI / 30);
    }
    pop();
}
