#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// Keywords for the programming language
const unordered_set<string> keywords = {
    "int", "float", "if", "else", "while", "for", "return", "void", "break", "continue"};

// Regex patterns for different token types
const regex keywordRegex("\\b(int|float|if|else|while|for|return|void|break|continue)\\b");
const regex identifierRegex("\\b[a-zA-Z_][a-zA-Z0-9_]*\\b");
const regex numberRegex("\\b\\d+\\b");
const regex operatorRegex("[-+*/=<>!&|]+");  
const regex specialSymbolRegex("[(){};,]");

// Tokenize function using regex
void lexicalAnalyzer(const string &code)
{
    vector<pair<string, string>> tokens; // Vector to store tokens and their types

    size_t position = 0;
    while (position < code.length())
    {
        string substring = code.substr(position);

        smatch match;

        // Match keyword
        if (regex_search(substring, match, keywordRegex) && match.position(0) == 0)
        {
            tokens.push_back({"Keyword", match.str(0)});
        }
        // Match identifier
        else if (regex_search(substring, match, identifierRegex) && match.position(0) == 0)
        {
            tokens.push_back({"Identifier", match.str(0)});
        }
        // Match number
        else if (regex_search(substring, match, numberRegex) && match.position(0) == 0)
        {
            tokens.push_back({"Number", match.str(0)});
        }
        // Match operator
        else if (regex_search(substring, match, operatorRegex) && match.position(0) == 0)
        {
            tokens.push_back({"Operator", match.str(0)});
        }
        // Match special symbol
        else if (regex_search(substring, match, specialSymbolRegex) && match.position(0) == 0)
        {
            tokens.push_back({"Special Symbol", match.str(0)});
        }
        // Handle whitespace
        else if (isspace(substring[0]))
        {
            position++;
            continue;
        }
        else
        {
            cerr << "Error: Unrecognized token at position " << position << ": " << substring[0] << endl;
            position++;
            continue;
        }

        // Move position to the end of the matched token
        position += match.length(0);
    }

    // Print the tokens
    cout << "Tokens identified:" << endl;
    for (const auto &token : tokens)
    {
        cout << token.first << ": " << token.second << endl;
    }
}

int main()
{
    string filename;
    cout << "Enter the filename for lexical analysis: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string code((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    lexicalAnalyzer(code);

    return 0;
}