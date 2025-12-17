#include "test_lib.hpp"
#include "test_resources.hpp"
#include "test_sdl.hpp"

int main()
{
    return run_tests({test_access_fs(),
                      test_tag_exists(),
                      test_tag_doesnt_exists(),
                      true, // Always true, because it passes if there isnt a compilation error.
                    },
                     {"Obtaining a handle to the embedded fs.",
                      "Checks if a proper tag exists.",
                      "Checks if an inproper tag doesnt exist.",
                      "Make sure SDL can be imported",
                    });
}
