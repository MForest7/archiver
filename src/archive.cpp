#include <archive.hpp>

namespace archive {

report launch_archiver(archive_mode mode, istream& in, ostream& out) {
    switch (mode) {
    	case archive_mode::encode : {
    		Encoder e(in);
    		return e.encode(out);
    	}
    	case archive_mode::decode : {
    		Decoder d(in);
    		return d.decode(out);
    	}
    	case archive_mode::uninitialized :
    		break;
    }
    throw logic_error("Unknown mode");
}

}