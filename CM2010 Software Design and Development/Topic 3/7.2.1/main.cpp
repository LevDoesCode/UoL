#include <iostream>

class Thing
{
  public:
    Thing(float x, float y)
    {
      this->y = x;
      this->y = y;
    }
    float getX()
    {
      return this->x;
    }
  private:
    float x;
    float y;
};

int addne(int input)
{
  return input + 1;
}

int main()
{
  int x = 10;
  float myFloat = 10.0f;
  int myInts[5] = {2, 4, 6, 8, 10};

  myInts[0] = 25;

  for(int i=0; i<sizeof(myInts)/sizeof(myInts[0]); ++i)
  {
    printf("F = %i \n", myInts[i]);
  }

  printf("x = %i \n", x);
  printf("f = %f \n", myFloat);
  printf("1st int = %i \n", myInts[0]);
  printf("one+: %i", addne(23));

  Thing aThing {10.2f, 10.5f};
  printf("Thing's x: %f \n", aThing.getX());
}