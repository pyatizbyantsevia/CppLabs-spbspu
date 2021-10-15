#include "tasks.hpp"

#include "functions.hpp"

void pyatizbyantsev::taskFour(const char* cmp, int size, std::ostream& out)
{
  std::vector< double > vector(size);
  pyatizbyantsev::fillRandom(vector.data(), size);

  print< pyatizbyantsev::strategyAt< double > >(vector, out, " ");
  sort< strategyAt< double > >(vector, sortMode< double >(cmp));
  print< pyatizbyantsev::strategyAt< double > >(vector, out, " ");
}
