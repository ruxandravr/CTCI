#ifndef CTCI_DYNAMIC_PROGRAMMING_H
#define CTCI_DYNAMIC_PROGRAMMING_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <string>

class DP
{
public:
  static int tripleStep(int n);

  static std::vector<std::pair<int, int> > getPath(std::vector<std::vector<int> > maze);
  static bool getPathH(int row, int column,
                       std::vector<std::pair<int, int> > &path, std::vector<std::vector<int> > maze);

  static int magicIndex(std::vector<int> array);
  static int magicIndexH(std::vector<int> array, int start, int finish);

  static int subsets(std::vector<int> domain);
  static void subsetsHelper(int step, std::vector<int> domain,
                            std::vector<std::vector <int> >  &set);

  static int subsets_2(std::vector<int> domain);
  static void addToSubset(int bluePrint, std::vector<int> domain,
                          std::vector<std::vector<int> > &solution);

  static int recursiveMultiply(int a, int b);
  static int recursiveMultiplyHelper(int a, int b);

  static void towersOfHanoiHelper(int n, std::stack<int> &first,
                                  std::stack<int> &aux, std::stack<int> &last);
  static std::stack<int> towersOfHanoi(int n);

  static int permutations_back(std::vector<int> domain);
  static void permutationsHelper(int step, int stop, std::vector<int> domain,
                                 std::vector<int> &solution, std::vector<std::vector<int> > &solutions);

  static int permutations_v1(std::string s);
  static std::vector<std::string> permutationsHelper_v1(std::string s);

  static int permutations_v2(std::string s);
  static std::vector<std::string> permutationsHelper_v2(std::string s);

  static int permutation_dups(std::string s);
  static void permutationHelper_dups(std::string solution, int remaining,
                                     std::string domain,std::vector<std::string> &solutions);

  static int parens(int count);
  static void parensHelper(int left, int right, std::string sol,
                           std::vector<std::string> &solutions);

  static int parens2(int count);
  static void parensHelper2(int n, std::unordered_set<std::string> &sol);

  static void paintFill(std::vector<std::vector<int> > &canvas, int row, int
                        column, int old, int color);

  static int coins_v1 (int n);
  static int coinsHelper(int n, std::vector<int> coinValues, int index);

  static int coins_v2 (int n);

  static void queens(int n);
  static bool checkMove(int step, std::vector<int> columns, int column);
  static void queensHelper(int step, std::vector<int> domain, std::vector<int> &sol,
                           std::vector<std::vector<int> > &solutions);

  static int booleanExpression(std::string s, bool result);
  static bool stringToBool(std::string s);
};

#endif