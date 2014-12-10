static int x;

int foo (int a)
{
  int b = a + 10;
  return b;
}

int bar (int y)
{
  int z = y + 20;
  return z;
}

int func2 ()
{
  x = 6;
}

void func()
{
  x = x + 5;
  func2 ();
}

int func3 ()
{
  x = 4;
}

void setBreakpoint ()
{
}

int
main ()
{
  int result;
  int b, c;
  c = 5;
  b = 3; 
    
  func (c);
  setBreakpoint ();
  func3 ();
  result = bar (b + foo (c));
  return 0; 
}
