int calculateArea(int width, in height)
{
  return width * height;
}
int main()
{
  int area = calculateArea(-10, -12); // non-sensical because a rectangle can't have negative dimensions
  return 0;
}