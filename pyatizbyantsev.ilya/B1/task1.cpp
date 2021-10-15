#include "tasks.hpp"
#include "functions.hpp"
#include "strategies.hpp"

void pyatizbyantsev::taskOne(const char* cmp, std::istream& in, std::ostream& out)
{
  std::vector< int > vectorFirst;

  int data;
  while (in && !(in >> data).eof())
  {
    if (in.fail() || in.bad())
    {
      throw std::invalid_argument("Incorrect input");
    }
    vectorFirst.push_back(data);
  }

  std::vector< int > vectorSecond(vectorFirst);
  std::forward_list< int > forwardList(vectorFirst.begin(), vectorFirst.end());

  sort< strategyIndex< int > >(vectorFirst, sortMode< int >(cmp));
  sort< strategyAt< int > >(vectorSecond, sortMode< int >(cmp));
  sort< strategyIterator< int > >(forwardList, sortMode< int >(cmp));
  print< pyatizbyantsev::strategyIndex< int > >(vectorFirst, out, " ");
  print< pyatizbyantsev::strategyAt< int > >(vectorSecond, out, " ");
  print< pyatizbyantsev::strategyIterator< int > >(forwardList, out, " ");
}
