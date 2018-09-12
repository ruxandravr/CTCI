#include "DynamicProgramming.h"

/* Maps used for memoization*/
std::unordered_map<int, int> tripleStepMap;
std::unordered_set<int> pathVisited;
std::unordered_set<int> permsVisited;
std::unordered_map<char, int> freq;
std::unordered_map<std::string, int> booleanMap;

/* Compute the number of ways to jump n steps using memoisztion
One can do n stept by doing n - 1 steps and then one more steps, or by doing
n - 2 stepts and then two more steps or by doing n - 3 and then three more steps. */
int DP::tripleStep(int n) {
  if (n == 1) {
    return 1;
  }

  if (n == 2) {
    return 2;
  }

  if (n == 3) {
    return 4;
  }

  if (tripleStepMap.find(n) != tripleStepMap.end()) {
    return tripleStepMap[n];
  }

  tripleStepMap[n] = tripleStep(n - 1) + tripleStep (n - 2) + tripleStep (n - 3);

  return tripleStepMap[n];
}

/* Get the path from the first position(0, 0) of a maze(2 dim array) to the
last position(n, n). */
std::vector<std::pair<int, int> > DP::getPath(std::vector<std::vector<int> > maze) 
{ 
  std::vector<std::pair<int, int> > path;
  getPathH(maze.size() - 1, maze[0].size() - 1, path, maze);
  return path;
}

/* Get the path from (0,0) to (row, column) using memoization. We can get to
(row, column) from either (row - 1, column) or (row, column - 1). */
bool DP::getPathH (int row, int column, 
  std::vector<std::pair<int, int> > &path, std::vector<std::vector<int> > maze) 
{ 
  // already found path
  if (pathVisited.find(row * maze.size() + column) != pathVisited.end()) {
    return false;
  }

  /* Got to the begining */
  if (row == 0 && column == 0) {
    path.push_back({row, column});
    return true;
  }

  /* Got outside the maze. */
  if (row < 0 || column < 0 || row >= maze.size() || column >= maze[0].size() ||
      maze[row][column] == 1) {
    return false;
  } 

  if (getPathH(row, column - 1, path, maze) || getPathH(row - 1, column, path, maze)) {
    path.push_back({row, column});
    return true;
  }

  pathVisited.insert(row * maze.size() + column);
  return false;
}

/* Get the index matching the element on that index in a sorted array that can
have duplicates. */
int DP::magicIndex(std::vector<int> array) {
  return magicIndexH(array, 0, array.size() - 1);
}

/* Search both left or right by reducing the interval. */
int DP::magicIndexH(std::vector<int> array, int start, int finish) {
  if (start < 0 || finish < 0 || start >= array.size() || finish >= array.size()) {
    return -1;
  }
  if (start > finish) {
    return -1;
  }

  int middle = start + (finish - start) / 2;

  if (array[middle] == middle) return array[middle];
  
  int leftBound = std::min(middle - 1, array[middle]);
  int left = magicIndexH(array, start, leftBound);
  if (left >= 0) {
    return left;
  }
  
  int rightBound = std::max(middle + 1, array[middle]);
  int right = magicIndexH(array, rightBound, finish);
  
  return right;

}

/* Compute all the subsets of a set recursively by computing all subsets
of the set without its last element, and adding the last elemnt to all the
previous found subsets.. */
int DP::subsets(std::vector<int> domain)
{
  std::vector<std::vector<int> > sol;
  subsetsHelper(domain.size(), domain, sol);
  
  return sol.size();
}

void DP::subsetsHelper(int step, std::vector<int> domain,
  std::vector<std::vector<int> > &solution) 
{
 if (step == 0) {
   std::vector<int> emptySol = {};
   solution.push_back(emptySol);
 } else {
   std::vector<std::vector<int> > prevSol;
   subsetsHelper(step - 1, domain, prevSol);
   /* all all the previous solutions. */
   for (auto v : prevSol) {
     solution.push_back(v);
   }
   /* concateate previous solutions with last element. */
   for (auto v : prevSol) {
     v.push_back(domain[step - 1]);
     solution.push_back(v);
    }
 }
}

/* Compute all the subsets of a set by printing all solutions corresponding 
to numbers from 0 to 2^set_length. */
int DP::subsets_2(std::vector<int> domain)
{
  std::vector<std::vector<int> > sol;
  int max = 1 << domain.size();
  for (int i = 0; i < max; ++i) {
    addToSubset(i, domain, sol);
  }
  return sol.size();
}

void DP::addToSubset(int bluePrint, std::vector<int> domain, 
std::vector<std::vector<int> > &solution)
{
  int index = 0;
  std::vector<int> currentSol;
  for (int i = bluePrint; i > 0; i >>= 1) {
    /* If it's one we print the current element. */
    if (i & 1) {
      currentSol.push_back(domain[index]);
    }
    index++;
  }
  solution.push_back(currentSol);
}

/* Multiply two numbers without the * operator, only by adding or bit shifting.*/
int DP::recursiveMultiply(int a, int b) 
{ 
  /* Multiply by the smaller number. */
  if (a < b) {
    return recursiveMultiplyHelper(a, b);
  } else {
    return recursiveMultiplyHelper(b, a);
  }
}

int DP::recursiveMultiplyHelper(int a, int b) {
  if (a == 0) {
    return 0;
  } else if (a == 1) {
    return b;
  } else {
    /* Compute a half of the product. */
    int half = recursiveMultiplyHelper(a >> 1, b);
    if (a % 2 == 0) {
      return half << 1;
    } else {
      /* If the multiplier is odd, add the multiplicand. */
      return (half << 1) + b;
    }
  }
}

/* Compute the towers of Hanoi problem. */
std::stack<int> DP::towersOfHanoi(int n) {
  std::stack<int> first;
  std::stack<int> aux;
  std::stack<int> last;

  for (int i = 0; i < n; ++i) {
    first.push(n - i);
  }

  towersOfHanoiHelper(n, first, last, aux);

  return last;
}

void DP::towersOfHanoiHelper(int n, std::stack<int> &first, std::stack<int> &last,
  std::stack<int> &aux) 
{
  if (n == 0) {
    return;
  }

  towersOfHanoiHelper(n - 1, first, aux, last);
  int disc = first.top();
  first.pop();
  last.push(disc);
  towersOfHanoiHelper(n - 1, aux, last, first);
}


/* Compute all the permutations of a given domain using backtracking. */
int DP::permutations_back(std::vector<int> domain)
{ 
  std::vector<std::vector<int> > solutions;
  std::vector<int> solution(domain.size());
  permutationsHelper(0, domain.size(), domain, solution, solutions);

  // for (auto v : solutions) {
  //   for (auto elem : v) {
  //     std::cout << elem << " ";
  //   }
  //   std::cout << "\n";
  // }
  return solutions.size();

}

/* Use memoization because we don't want duplicate values. */
void DP::permutationsHelper(int step, int stop, std::vector<int> domain, 
std::vector<int> &solution, std::vector<std::vector<int> > &solutions)
{ 
  /* Got to the solution. */
  if (step == stop) {
    solutions.push_back(solution);
    return;
  }

  for (int i = 0; i < domain.size(); ++i) {
    if (permsVisited.find(domain[i]) == permsVisited.end()) {
      /* Add a new element. */
      solution[step] = domain[i];
      permsVisited.insert(domain[i]);
      /* Continue recursing. */
      permutationsHelper(step + 1, stop, domain, solution, solutions);
      /* Refactor domain. */
      permsVisited.erase(domain[i]);
    }
  }
}


/* To generate the permutations of a string of size n we generate all permutations
of the string of size n - 1 and then introduce the element on position n
in all the posibile positions in the previous generated strings. */
std::vector<std::string> DP::permutationsHelper_v1(std::string s)
{ 
  std::vector<std::string> result;
  if (s.length() == 0) {
    std::string s = "";
    result.push_back(s);
    return result;
  }

  std::string c;
  c.push_back(s[s.size() - 1]);
  s.pop_back();
  std::vector<std::string> previous = permutationsHelper_v1(s);
  for (auto prev : previous) {
    if (prev.size() == 0) { // the previous result was null
      result.push_back(c);  // we have a permutation with only 1 element
    } else {
      /* Insert the last character in all the positions. */
      for (int i = 0; i < prev.size(); ++i) {
        std::string copy = prev;
        std::string newString = copy.insert(i, c);
        result.push_back(newString);
      }
      /* Insert the last char at the end of the string. */
      prev += c;
      result.push_back(prev); 
    }
  }

  return result;
}

/* Compute the permutations of a given set by using previous solutions. */
int DP::permutations_v1(std::string s)
{
  std::vector<std::string> res = permutationsHelper_v1(s);
  // for (auto r : res) {
  //   std::cout << r << "\n";
  // }
  return res.size();
}

/* Compute the permutations of a given set by using previous solutions. */
int DP::permutations_v2(std::string s)
{
  std::vector<std::string> res = permutationsHelper_v2(s);
  // for (auto r : res) {
  //   std::cout << r << "\n";
  // }
  return res.size();
}

/* Compute the permutations of a string of size n by generating all the n - 1
combinations of strings permutation and adding the missing 
character at the begining. */
std::vector<std::string> DP::permutationsHelper_v2(std::string domain)
{
  std::vector<std::string> result;

  if (domain.size() == 0) {
    std::string s = "";
    result.push_back(s);
    return result;
  }

  /* Extract one char at all indexes*/
  for (int i = 0; i < domain.size(); ++i) {
    std::string first = domain.substr(0, i);
    std::string last = domain.substr(i + 1);
    /* Compute all the permutations of the string without that char. */
    std::vector<std::string> prevStrings = permutationsHelper_v2(first + last);
    for (auto prev : prevStrings) {
      /* Add that char at the begining. */
      std::string newS = domain[i] + prev;
      result.push_back(newS);
    } 
  }
  return result;
}

/* Generate all permutations of a string which has duplicates by calculating the
frequency of each character. */
int DP::permutation_dups(std::string s) {
  for (auto c : s) {
    if (freq.find(c) != freq.end()) {
      freq[c] = freq[c] + 1;
    } else {
      freq[c] = 1;
    }
  }

  std::vector<std::string> res;
  std::string sol;
  permutationHelper_dups(sol, s.length(), s, res);

  // for (auto r : res) {
  // std::cout << r << "\n";
  // }
  return res.size();
}

void DP::permutationHelper_dups(std::string solution, int remaining,
  std::string domain, std::vector<std::string> &solutions)
{
  if (remaining == 0) {
    solutions.push_back(solution);
    return;
  }

  for (auto elem : freq) {
    if (freq[elem.first] != 0) {
      solution = solution + elem.first;
      freq[elem.first] = freq[elem.first] - 1;
      permutationHelper_dups(solution, remaining - 1, domain, solutions);
      solution.pop_back();
      freq[elem.first] = freq[elem.first] + 1;      
    }
  }
}

/* Print all the ways in which we can correctly write a set of n parens
(n left parens and n right parens). */
int DP::parens(int count) 
{
  std::vector<std::string> solutions;
  std::string solution = "";
  parensHelper(count, count, solution, solutions);

  // for (auto s : solutions) {
  //   std::cout << s << "\n";
  // }
  return solutions.size();
}

/* Keep track of how many left and right parents we have left.*/
void DP::parensHelper(int left, int right, std::string sol, 
std::vector<std::string> &solutions) 
{
  if (left < 0 || right < 0) {
    return;
  }
  /* Inserted all the parens. */
  if (left == 0 && right == 0) {
    solutions.push_back(sol);
  } 
  /* We can always insert a left parent if we have one. */
  if (left > 0) {
    parensHelper(left - 1, right, sol + "(", solutions);

    /* If we have more right parens then left, we can insert a right paren. */
    if (left < right)
    parensHelper(left, right - 1, sol + ")", solutions);
    
  } else {
    /* Insert right parens at the end. */
    parensHelper(left, right - 1, sol + ")", solutions);
    
  }
}

/* Print all the parens by using previous solutions. */
int DP::parens2(int count)
{
  std::unordered_set<std::string> res;
  parensHelper2(count, res);

  // for (auto str : res) {
  //   std::cout << str << "\n";
  // }
  return res.size();

}

/* Generate all the ways in which we can arrange n - 1 parens, and then
add a paren after every left paren, and at the beginign.*/
void DP::parensHelper2(int n, std::unordered_set<std::string> &sol)
{ 
  if (n <= 0) {
    std::string rez = "";
    sol.insert(rez);
    return;
  }
  std::unordered_set<std::string> prev;
  parensHelper2(n - 1, prev);
  for (auto elem : prev) {
    std::string elemCopy;
    /* Insert a set of parens after every left one. */
    for (int i = 0; i < elem.size(); ++i) {
      if (elem[i] == '(') {
        elemCopy = elem;
        elemCopy = elemCopy.insert(i + 1, "()");
        sol.insert(elemCopy);
      }
    }
    /* Insert a set of parens at the begining. */
    elemCopy = "()" + elem;
    sol.insert(elemCopy);    
  }
}

/* Fill all the neighbouring cells of (row, column) of color old with color
color. */
void DP::paintFill(std::vector<std::vector<int> > &canvas, int row, int
  column, int old, int color) 
{
  /* Directions vector. */
  std::vector<int> dx = {-1, 0, 1, 0};
  std::vector<int> dy = {0, -1, 0, 1};

  if (canvas[row][column] == old) {
    canvas[row][column] = color;
  } else {
    return;
  }

  for (int i = 0; i < 4; ++i) {
    if (row + dy[i] >= 0 && row + dy[i] < canvas.size() && column + dx[i] >= 0 &&
      column + dx[i] < canvas[0].size()) {
        paintFill(canvas, row + dy[i], column + dx[i], old, color);
      } 
  }
}


/* Generate all the numbers of changing n cents in smaller value cents. */
int DP::coins_v1(int n) 
{
  std::vector<int> coinValues = {25, 10, 5, 1};
  return coinsHelper(n, coinValues, 0);
}

/* Change the sum recursively with cents of smaller value. */
int DP::coinsHelper(int n, std::vector<int> coinValues, int index)
{ 
  if (index >= coinValues.size() - 1) {
    return 1;
  }
  int current = coinValues[index];
  int ways = 0;
  for (int i = 0; i * current <= n; ++i) {
    int remaining = n - i * current;
    ways += coinsHelper(remaining, coinValues, index + 1);
  }
  return ways;
}

/* Use a single array which computes all the ways to change sums from 1 to n. */
int DP::coins_v2 (int n)
{
  std::vector<int> values(n + 1);
  std::vector<int> coinValues = {1, 5, 10, 25};

  values[0] = 1;

  for (int k = 0; k < coinValues.size(); ++k) {
    int coin = coinValues[k];
    for (int i = 1; i < values.size(); ++i) {
      if (i >= coin) {
        values[i]+= values[i - coin];
      }
    }
  }
  return values[n];
}

/* Display all the ways to arrange n queens on a chess board. */
void DP::queens(int n)
{

  std::vector<std::vector<int> > solutions;
  std::vector<int> solution(n);
  std::vector<int> domain;
  for (int i = 0; i < n; ++i) {
    domain.push_back(i);
 } 

  queensHelper(0, domain, solution, solutions);

  // for (auto sol : solutions) {
  //   for (auto elem : sol) {
  //     std::cout << elem << " ";
  //   }
  //   std::cout << "\n";
  // }
}

/* Check that the column is valid: not on the same line/ diagonal. */
bool DP::checkMove(int step, std::vector<int> columns, int column)
{
  for (int row = 0; row <= step; ++row) {
    int column2 = columns[row];

    // same line
    if (column2 == column) {
      return false;
    }

    // same diagonal
    if (abs (column2 - column) == abs(step - row)) {
      return false;
    }
  }
  return true;
}

/* Compute all the valid columns in which we can add a queen, since all the rows
are different. sol[i] = j means queen on position (i, j). */
void DP::queensHelper(int step, std::vector<int> domain, std::vector<int> &sol,
std::vector<std::vector<int> > &solutions)
{
  if (step == domain.size()) {
    solutions.push_back(sol);
    return;
  }
  for (int column = 0; column < domain.size(); ++column) {
    if (checkMove(step, sol, column)) {
      sol[step] = column;
      queensHelper(step + 1, domain, sol, solutions);
    }
  }
}

bool DP::stringToBool(std::string s)
{
  if (s == "0") {
    return false;
  }
  return true;
}

/* Compute all the ways in which we can parenthesize a boolean expresion to
the given result (true/ false) using memoization. */
int DP::booleanExpression(std::string s, bool result)
{  
  /* We got to only a boolean. */
  if (s.length() == 1) {
    return stringToBool(s) == result; 
  }


  if (booleanMap.find(s + (result ? "1" : "0")) != booleanMap.end()) {
    return booleanMap[s + (result ? "1" : "0")];
  }

  /* For every symbol (, ^, &) try to put parens before and after it and sum
  all the possilbe combinations. */
  int ways = 0;
  for (int i = 1; i < s.length(); i = i + 2) {
    std::string left = s.substr(0, i); // expresion before current operator
    std::string right = s.substr(i + 1); // expresion before current operator
    int leftTrue = booleanExpression(left, true);
    int leftFalse = booleanExpression(left, false);
    int rightTrue = booleanExpression(right, true);
    int rightFalse = booleanExpression(right, false);

    /* Total ways. */
    int total = (leftTrue + leftFalse) * (rightTrue + rightFalse);
    int totalTrue = 0;

    /* True ways. */
    if (s[i] == '&') {
      totalTrue = rightTrue * leftTrue;
    } else if (s[i] == '|') {
      totalTrue = rightTrue * leftTrue + rightTrue * leftFalse + rightFalse * leftTrue; 
    } else if (s[i] == '^') {
      totalTrue = rightTrue * leftFalse + rightFalse * leftTrue;       
    }

    /* Keep score only of the needed results. */
    int subways = result ? totalTrue : total - totalTrue;
    ways += subways;
  }
  booleanMap[s + (result ? "1" : "0")] = ways;
  return ways;
}
