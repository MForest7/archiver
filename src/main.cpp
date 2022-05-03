#include <iostream>
#include <fstream>
#include <exception>
#include <flags.hpp>
#include <archive.hpp>
#include <report.hpp>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::endl;
using std::exception;
using std::logic_error;

using namespace flags;
using namespace archive;

int main(int argc, char* argv[])
{
    FlagsValidator FLAGS = FlagsValidator({
        {"-c", "-c", false},
        {"-u", "-u", false},
        {"-f", "--file", true},
        {"-o", "--output", true}
    });

    try {
        bool mode_initialized = false;
        bool input_initialized = false;
        bool output_initialized = false;

        archive_mode mode = archive_mode::uninitialized;
        string input_filename;
        string output_filename;

        for (int i = 1; i < argc; i++) {
            string arg = string(argv[i]);
            flag f = FLAGS.get_by_name(arg);

            if (f.name == "-c") {
                mode_initialized = true;
                mode = archive_mode::encode;
            }
            if (f.name == "-u") {
                mode_initialized = true;
                mode = archive_mode::decode;
            }
            if (f.name == "-f") {
                input_initialized = true;
            }
            if (f.name == "-o") {
                output_initialized = true;
            }

            if (f.need_arg) {
                if (i + 1 == argc)
                    throw logic_error("Missing argument for " + f.name);

                i++;

                string flag_arg = string(argv[i]);
                if (f.name == "-f") {
                    input_filename = flag_arg;
                }
                if (f.name == "-o") {
                    output_filename = flag_arg;
                }
            }
        }

        if (!mode_initialized)
            throw logic_error("Missing mode");
        if (!input_initialized)
            throw logic_error("Missing input file");
        if (!output_initialized)
            throw logic_error("Missing output file");

        ifstream fin(input_filename);
        ofstream fout(output_filename);

        if (fin.fail())
            throw logic_error("Can't open file: " + input_filename);
        if (fout.fail())
            throw logic_error("Can't open file: " + output_filename);

        report r = launch_archiver(mode, fin, fout);
        cout << r.size_input << endl;
        cout << r.size_output << endl;
        cout << r.size_additional << endl;

        fin.close();
        fout.close();

    }
    catch(const std::ios_base::failure& e) {
        cout << "[I/O error]: " << e.what() << endl;
    }
    catch(const exception &e) {
        cout << "[Error]: " << e.what() << endl;
    }
}