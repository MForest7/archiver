#ifndef ARCHIVE_HPP_INCLUDED
#define ARCHIVE_HPP_INCLUDED

#include <encoder.hpp>
#include <decoder.hpp>
#include <exception>

using std::size_t;
using std::string;
using std::logic_error;

namespace archive {

enum archive_mode {
    encode, decode, uninitialized
};

report launch_archiver(archive_mode mode, istream& in, ostream& out);

}

#endif // ARCHIVE_HPP_INCLUDED