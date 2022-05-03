#ifndef FLAGS_HPP_INCLUDED
#define FLAGS_HPP_INCLUDED

#include <exception>
#include <vector>
#include <map>

using std::size_t;
using std::logic_error;
using std::vector;
using std::map;
using std::string;

namespace flags {

struct flag {
    string name;
    string full_name;
    bool need_arg;
};

class FlagsValidator {

public:
    FlagsValidator(vector <flag> _flags);
    ~FlagsValidator() = default;
    FlagsValidator(const FlagsValidator& other);
    FlagsValidator& operator=(const FlagsValidator& other);

    bool known_flag(string name);

    flag get_by_name(string name);

private:
    vector <flag> flags;
    vector <bool> used;
    map <string, size_t> table;

    void swap(FlagsValidator& other);
};

}

#endif // FLAGS_HPP_INCLUDED