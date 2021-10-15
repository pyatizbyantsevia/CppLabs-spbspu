#include "tasks.hpp"

#include <sstream>
#include <algorithm>

#include "phone-book-interface.hpp"
#include "functions.hpp"

namespace lab = pyatizbyantsev;

int lab::taskOne(std::istream& in, std::ostream& out)
{
  lab::PhoneBookInterface bookInterface;
  std::string stream;

  while (std::getline(in, stream) && !stream.empty())
  {
    try
    {
      std::istringstream input(stream);
      std::string command;
      input >> command;
      if (command == "add")
      {
        std::string number;
        input >> number;
        checkNumber(number);

        std::string name = checkName(input);

        bookInterface.add({number, name});
      }
      else if (command == "store")
      {
        std::string oldMarkName;
        input >> oldMarkName;
        checkMarkName(oldMarkName);

        std::string newMarkName;
        input >> newMarkName;
        checkMarkName(newMarkName);

        bookInterface.store(oldMarkName, newMarkName);
      }
      else if (command == "insert")
      {
        std::string insertion;
        input >> insertion;
        if (insertion != "before" && insertion != "after")
        {
          throw std::invalid_argument("<INVALID COMMAND>");
        }
        std::string markName;
        input >> markName;
        checkMarkName(markName);

        std::string number;
        input >> number;
        checkNumber(number);

        std::string name = checkName(input);

        if (input && bookInterface.contains(markName))
        {
          if (insertion == "before")
          {
            bookInterface.insertBefore(markName, {number, name});
          }
          else if (insertion == "after")
          {
            bookInterface.insertAfter(markName, {number, name});
          }
        }
      }
      else if (command == "delete")
      {
        std::string markName;
        input >> markName;
        checkMarkName(markName);

        bookInterface.deleteNote(markName);
      }
      else if (command == "show")
      {
        std::string markName;
        input >> markName;
        checkMarkName(markName);

        out << bookInterface.show(markName) << '\n';
      }
      else if (command == "move")
      {
        std::string mark;
        std::string steps;
        input >> mark >> steps;

        if (bookInterface.contains(mark))
        {
          try
          {
            int stepsNum = std::stoi(steps);
            bookInterface.move(mark, stepsNum);
          }
          catch (const std::invalid_argument&)
          {
            if ((steps == "first") || (steps == "last"))
            {
              bookInterface.move(mark, steps);
            }
            else
            {
              throw std::invalid_argument("<INVALID STEP>");
            }
          }
        }
        else
        {
          throw std::invalid_argument("<INVALID BOOKMARK>");
        }
      }
    }
    catch (const std::invalid_argument& e)
    {
      out << e.what() << "\n";
    }
  }
  return 0;
}
