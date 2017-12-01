#include <iostream>
#include <string>
#include <vector>

//The original idea for this is here:
//https://stackoverflow.com/questions/15992317/determing-if-string-has-all-unique-characters

/*
 * This works b/c the index's location is the decimal representation of the
 * ASCII Character. This has the idea of working as a very simple hash map 
 * If the position in the buffer is already set to true then there is a 
 * duplicate.
 */

bool isUniqueChars( const std::string &str )
{
    if(str.length() > 127) return false;
    
    std::vector<bool> char_set(127);
    
    for (unsigned i=0; i < str.length(); i++)
    {
        int val = str[i];
        if (char_set[val]){
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

int main()
{
    std::vector<std::string> words = {"abcde", "hello", "apple", "kite", "paddle"};
    
    for ( const auto& word: words){
        std::cout << word << std::string(": ");
        isUniqueChars(word) ? std::cout << "Unique \n" : std::cout << "Duplicates Exist \n";
    }
}

/* ***** Output ****
  abcde: Unique 
  hello: Duplicates Exist 
  apple: Duplicates Exist 
  kite: Unique 
  paddle: Duplicates Exist 
*/
