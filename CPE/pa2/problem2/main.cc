#include <iostream>
#include "calculator.h"

using namespace std;

double xyz[3];
int isVarD[3];

bool isInteger(const string& str);
bool isDouble(const string& str);
void equation(int v1, int v2, char cal);
void equation(double v1, double v2, char cal);
void equation(string v1, int v2, char cal);
void equation(string v1, double v2, char cal);
void equation(int v1, string v2, char cal);
void equation(double v1, string v2, char cal);
void equation(string v1, string v2, char cal);

int main(){
  //write your code here
  string s = "";
  
  try
  {  
    while (1)
    {
      cout << "Enter your equation to calculate: ";
      getline(cin, s);

      if (s == "quit") break;

      string var1 = "";
      char cal = '0';
      string var2 = "";
      
      bool isChar = false;
      int next = 0;
      int dot = 0;
      for (char c : s)
      {
        if (((c >= '0' && c <= '9') || c == '.' || c =='x' || c == 'y' || c == 'z') && next == 0)
        {
          var1 += c;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '=')
        {
          cal = c;
          next++;
        }
        else if (((c >= '0' && c <= '9') || c == '.' || c =='x' || c == 'y' || c == 'z') && next == 1)
        {
          var2 += c;
          if (c == '.') dot = 1;
        }
        else if (c != ' ')
        {
          throw runtime_error("Invalid input");
        }
      }

      if(!isInteger(var1) && !isDouble(var1)) isChar = true;

      if(!isInteger(var2) && !isDouble(var2)) isChar = true;

      if (!isChar) // int 혹은 double
      {
        if (isInteger(var1) && isInteger(var2))
        {
          auto v1 = stoi(var1);
          auto v2 = stoi(var2);
          equation(v1, v2, cal);
        }
        else
        {
          auto v1 = stod(var1);
          auto v2 = stod(var2);
          equation(v1, v2, cal);
        }
      }
      else if(!isInteger(var1) && !isDouble(var1)) // var1이 변수
      {
        string v1 = var1;
        if (cal == '=') isVarD[v1[0] - 'x'] = dot; // var1이 int인지 double인지를 체크해서 넘겨줌
        if (isInteger(var2))
        {
          auto v2 = stoi(var2);
          equation(v1, v2, cal);
        }
        else if (isDouble(var2))
        {
          auto v2 = stod(var2);
          equation(v1, v2, cal);
        }
        else // 둘 다 변수
        {
          string v2 = var2;
          equation(v1, v2, cal);
        }
      }
      else if(!isInteger(var2) && !isDouble(var2)) // var2가 변수
      {
        string v2 = var2;
        if (isInteger(var1))
        {
          auto v1 = stoi(var1);
          equation(v1, v2, cal);
        }
        else if (isDouble(var1))
        {
          auto v1 = stod(var1);
          equation(v1, v2, cal);
        }
      }
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << "Answer: " << e.what() << '\n';
  }

  return 0;
}

bool isInteger(const string& str)
{
    try
    {
      size_t pos;
      stoi(str, &pos);
      return pos == str.size();
    }
    catch (invalid_argument&)
    {
      return false;
    }
    catch (out_of_range&)
    {
      return false;
    }
}

bool isDouble(const string& str)
{
    try
    {
      size_t pos;
      stod(str, &pos);
      return pos == str.size();
    }
    catch (invalid_argument&)
    {
      return false;
    }
    catch (out_of_range&)
    {
      return false;
    }
}

/*======================================================*/

void equation(int v1, int v2, char cal)
{
  Calculator c;

  if (cal == '+') c.addition(v1, v2);
  else if (cal == '-') c.subtraction(v1, v2);
  else if (cal == '*') c.multiplication(v1, v2);
  else if (cal == '/') c.division(v1, v2);
  else if (cal == '%') c.remainder(v1, v2);
  else if (cal == '^') c.exponentiation(v1, v2);
}

void equation(double v1, double v2, char cal)
{
  Calculator c;

  if (cal == '+') c.addition(v1, v2);
  else if (cal == '-') c.subtraction(v1, v2);
  else if (cal == '*') c.multiplication(v1, v2);
  else if (cal == '/') c.division(v1, v2);
  else if (cal == '%') c.remainder(v1, v2);
  else if (cal == '^') c.exponentiation(v1, v2);
}

/*======================================================*/

void equation(string v1, int v2, char cal)
{
  Calculator c;

  if (v1 != "x" && v1 != "y" && v1 != "z") throw runtime_error("Invalid input");

  char c1 = v1[0];
  double dvar2 = static_cast<double>(v2);
  if (cal == '=')
  {
    xyz[c1 - 'x'] = dvar2;
    return;
  }
  if (isVarD[c1 - 'x'] == 1)
  {
    if (cal == '+') c.addition(xyz[c1 - 'x'], dvar2);
    else if (cal == '-') c.subtraction(xyz[c1 - 'x'], dvar2);
    else if (cal == '*') c.multiplication(xyz[c1 - 'x'], dvar2);
    else if (cal == '^') c.exponentiation(xyz[c1 - 'x'], dvar2);
    else if (cal == '/') c.division(xyz[c1 - 'x'], dvar2);
    else if (cal == '%') c.remainder(xyz[c1 - 'x'], dvar2);
  }
  else
  {
    int ivar1 = static_cast<int>(xyz[c1 - 'x']);
    if (cal == '+') c.addition(ivar1, v2);
    else if (cal == '-') c.subtraction(ivar1, v2);
    else if (cal == '*') c.multiplication(ivar1, v2);
    else if (cal == '^') c.exponentiation(ivar1, v2);
    else if (cal == '/') c.division(ivar1, v2);
    else if (cal == '%') c.remainder(ivar1, v2);
  }
}

void equation(string v1, double v2, char cal)
{
  Calculator c;

  if (v1 != "x" && v1 != "y" && v1 != "z") throw runtime_error("Invalid input");

  char c1 = v1[0];
  if (cal == '=') xyz[c1 - 'x'] = v2;
  else if (cal == '+') c.addition(xyz[c1 - 'x'], v2);
  else if (cal == '-') c.subtraction(xyz[c1 - 'x'], v2);
  else if (cal == '*') c.multiplication(xyz[c1 - 'x'], v2);
  else if (cal == '^') c.exponentiation(xyz[c1 - 'x'], v2);
  else if (cal == '/') c.division(xyz[c1 - 'x'], v2);
  else if (cal == '%') c.remainder(xyz[c1 - 'x'], v2);
}

/*======================================================*/

void equation(int v1, string v2, char cal)
{
  Calculator c;

  if (v2 != "x" && v2 != "y" && v2 != "z") throw runtime_error("Invalid input");

  char c2 = v2[0];
  double dvar1 = static_cast<double>(v1);
  if (cal == '=')
  {
    throw runtime_error("Invalid input");
  }
  if (isVarD[c2 - 'x'] == 1)
  {
    if (cal == '+') c.addition(dvar1, xyz[c2 - 'x']);
    else if (cal == '-') c.subtraction(dvar1, xyz[c2 - 'x']);
    else if (cal == '*') c.multiplication(dvar1, xyz[c2 - 'x']);
    else if (cal == '^') c.exponentiation(dvar1, xyz[c2 - 'x']);
    else if (cal == '/') c.division(dvar1, xyz[c2 - 'x']);
    else if (cal == '%') c.remainder(dvar1, xyz[c2 - 'x']);
  }
  else
  {
    int ivar2 = static_cast<int>(xyz[c2 - 'x']);
    if (cal == '+') c.addition(v1, ivar2);
    else if (cal == '-') c.subtraction(v1, ivar2);
    else if (cal == '*') c.multiplication(v1, ivar2);
    else if (cal == '^') c.exponentiation(v1, ivar2);
    else if (cal == '/') c.division(v1, ivar2);
    else if (cal == '%') c.remainder(v1, ivar2);
  }
}

void equation(double v1, string v2, char cal)
{
  Calculator c;

  if (v2 != "x" && v2 != "y" && v2 != "z") throw runtime_error("Invalid input");

  char c2 = v2[0];
  if (cal == '=') xyz[c2 - 'x'] = v1;
  else if (cal == '+') c.addition(v1, xyz[c2 - 'x']);
  else if (cal == '-') c.subtraction(v1, xyz[c2 - 'x']);
  else if (cal == '*') c.multiplication(v1, xyz[c2 - 'x']);
  else if (cal == '^') c.exponentiation(v1, xyz[c2 - 'x']);
  else if (cal == '/') c.division(v1, xyz[c2 - 'x']);
  else if (cal == '%') c.remainder(v1, xyz[c2 - 'x']);
}

/*======================================================*/

void equation(string v1, string v2, char cal)
{
  Calculator c;

  if (v1 != "x" && v1 != "y" && v1 != "z") throw runtime_error("Invalid input");
  else if (v2 != "x" && v2 != "y" && v2 != "z" && v2 != "") throw runtime_error("Invalid input");

  char c1 = v1[0];
  char c2 = v2[0];

  if (cal == '0')
  {
    if (isVarD[c1 - 'x'] == 1)
    {
      string s = to_string(xyz[c1 - 'x']);
      cout << "Answer: " << s << endl;
      return;
    }
    cout << "Answer: " << xyz[c1 - 'x'] << endl;
    return;
  }

  if (v2 == "") throw runtime_error("Invalid input");
  if (v2 == "0") throw runtime_error("Operation disallowed");

  if (cal == '=')
  {
    xyz[c1 - 'x'] = xyz[c2 - 'x'];
    isVarD[c1 - 'x'] = isVarD[c2 - 'x'];
    return;
  }

  if (isVarD[c1 - 'x'] == 0 && isVarD[c2 - 'x'] == 0)
  {
    int ivar1 = static_cast<int>(xyz[c1 - 'x']);
    int ivar2 = static_cast<int>(xyz[c2 - 'x']);
    if (cal == '+') c.addition(ivar1, ivar2);
    else if (cal == '-') c.subtraction(ivar1, ivar2);
    else if (cal == '*') c.multiplication(ivar1, ivar2);
    else if (cal == '/') c.division(ivar1, ivar2);
    else if (cal == '%') c.remainder(ivar1, ivar2);
    else if (cal == '^') c.exponentiation(ivar1, ivar2);
  }
  else
  {
    if (cal == '+') c.addition(xyz[c1 - 'x'], xyz[c2 - 'x']);
    else if (cal == '-') c.subtraction(xyz[c1 - 'x'], xyz[c2 - 'x']);
    else if (cal == '*') c.multiplication(xyz[c1 - 'x'], xyz[c2 - 'x']);
    else if (cal == '/') c.division(xyz[c1 - 'x'], xyz[c2 - 'x']);
    else if (cal == '%') c.remainder(xyz[c1 - 'x'], xyz[c2 - 'x']);
    else if (cal == '^') c.exponentiation(xyz[c1 - 'x'], xyz[c2 - 'x']);
  }
}
