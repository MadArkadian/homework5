#include <list>

void _possibleParenthesis(std::list<std::string> & result, int open, int clsoed, int total);
// n: size of the problem
// result: a list of string, each string represents a case of valid parentheses of size n
void possibleParenthesis(int n, std::list<std::string> & result)
{
    _possibleParenthesis(result, 0, 0, n);
}

void _possibleParenthesis(std::list<std::string> & result, int open, int closed, int total){
    static std::string answer;
    if (closed == total){
        std::cout << answer << std::endl;
        result.push_back(answer);
    }

    if (open > closed){
        answer.push_back('}');
        _possibleParenthesis(result, open, closed + 1, total);
        answer.pop_back();
    }
    if (open < total){
        answer.push_back('{');
        _possibleParenthesis(result, open + 1, closed, total);
        answer.pop_back();
    }
}

