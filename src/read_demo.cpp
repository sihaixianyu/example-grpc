#include <fstream>
#include "fmt/base.h"

#include "example.pb.h"

using namespace std::string_view_literals;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fmt::println("Expect 2 params, got {} params.", argc);
    }

    auto person = example::Person();

    auto input= std::fstream(argv[1], std::ios::in | std::ios::binary);
    person.ParseFromIstream(&input);

    fmt::println("{}", person.DebugString());
}
