#include <fstream>
#include "fmt/base.h"

#include "example.pb.h"

using namespace std::string_view_literals;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fmt::println("Expect 2 params, got {} params.", argc);
    }
    
    auto p = example::Person();
    p.set_id(0);
    p.set_name("ztx");

    auto r = p.add_reports();
    r->set_gender(example::Person::Gender::Person_Gender_Male);
    r->set_suggestion("Increase the intensity of your exercise.");

    auto output = std::fstream(argv[1], std::ios::out | std::ios::trunc | std::ios::binary);
    p.SerializePartialToOstream(&output);
}
