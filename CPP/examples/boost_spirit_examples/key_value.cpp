//Accessed 3/20/2014 - http://svn.boost.org/svn/boost/trunk/libs/spirit/example/qi/key_value_sequence_ordered.cpp
//g++ key_value.cpp --std=c++11 -static -L/opt/lib/  -I /opt/include/
//
#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/include/std_pair.hpp>

#include <iostream>
#include <map>

namespace client
{
    namespace qi = boost::spirit::qi;

    typedef std::vector<std::pair<std::string, std::string> > pairs_type;

    template <typename Iterator>
    struct key_value_sequence_ordered
      : qi::grammar<Iterator, pairs_type()>
    {
        key_value_sequence_ordered()
          : key_value_sequence_ordered::base_type(query)
        {
          
            query =  pair >> *((qi::lit('')) >> pair); // * indicates Zero or more
            pair  =  key >> -('=' >> value);             // The  - means optional, so we should be able to grab spaces
            key   =  +qi::char_("0-9");                  // + means One or More 
            value = +~qi::char_("");                   // The ~ is only used with chars, it's not available for other types
        }

        qi::rule<Iterator, pairs_type()> query;
        qi::rule<Iterator, std::pair<std::string, std::string>()> pair;
        qi::rule<Iterator, std::string()> key, value;
    };
}

///////////////////////////////////////////////////////////////////////////////
int main(){
    namespace qi = boost::spirit::qi;

    //    std::string input("key2=value2;key1;key3=value3");
    std::string input("8=FIX.4.29=8835=034=3098369=317652=20140310-21:27:27.73449=CME50=G56=3SR063N57=3SRX143=US,IL10=195");
    std::string::iterator begin = input.begin();
    std::string::iterator end = input.end();

    client::key_value_sequence_ordered<std::string::iterator> p;
    client::pairs_type v;

    if (!qi::parse(begin, end, p, v))
    {
        std::cout << "-------------------------------- \n";
        std::cout << "Parsing failed\n";
        std::cout << "-------------------------------- \n";
    }
    else
    {
        std::cout << "-------------------------------- \n";
        std::cout << "Parsing succeeded, found entries:\n";
        client::pairs_type::iterator end = v.end();
        for (client::pairs_type::iterator it = v.begin(); it != end; ++it)
        {
            std::cout << (*it).first;
            if (!(*it).second.empty())
                std::cout << "=" << (*it).second;
            std::cout << std::endl;
        }
        std::cout << "---------------------------------\n";
    }
    return 0;
}
