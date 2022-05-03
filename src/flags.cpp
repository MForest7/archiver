#include <flags.hpp>
#include <algorithm>

namespace flags {

FlagsValidator::FlagsValidator(vector <flag> _flags) : flags(_flags) {
    for (size_t i = 0; i < flags.size(); i++) {
        table[flags[i].name] = i;
        table[flags[i].full_name] = i;
    }

    used.resize(flags.size());
}

FlagsValidator::FlagsValidator(const FlagsValidator& other) {
    flags = other.flags;
    used = other.used;
    table = other.table;
}

void FlagsValidator::swap(FlagsValidator& other) {
    std::swap(flags, other.flags);
    std::swap(used, other.used);
    std::swap(table, other.table);
}

FlagsValidator& FlagsValidator::operator=(const FlagsValidator& other) {
    if (this == &other)
        return *this;

    FlagsValidator tmp(other);
    swap(tmp);
    return *this;
}

bool FlagsValidator::known_flag(string name) {
    return (table.find(name) != table.end());
}

flag FlagsValidator::get_by_name(string name) {
    if (table.find(name) != table.end()) {
        if (!used[table[name]]) {
            used[table[name]] = true;
            return flags[table[name]];
        }
        throw logic_error("Duplicate flag: " + name);
    }
    throw logic_error("Unknown flag: " + name);
}

}