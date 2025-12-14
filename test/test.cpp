#include "test_lib.hpp"
#include <cmrc/cmrc.hpp>
#include <string>
#include <iostream>

#ifndef TAG_FAMILY
#define TAG_FAMILY ""
#endif

CMRC_DECLARE(tags);

bool test_access_fs() {
    auto fs = cmrc::tags::get_filesystem();
    if (!(&fs)) {
        return false;
    }
    return true;
}

bool test_tag_exists() {
    auto fs = cmrc::tags::get_filesystem();
    std::string path = "tags/";
    path.append(TAG_FAMILY);
    path.append("-15.png");

    return fs.exists(path);
}

bool test_tag_doesnt_exists()
{
    auto fs = cmrc::tags::get_filesystem();
    std::string path = "tags/not-a-real-tag.png";
    
    return !fs.exists(path);
}

int main() {
    return run_tests({
        test_access_fs(),
        test_tag_exists(),
        test_tag_doesnt_exists()
    }, {
        "Obtaining a handle to the embedded fs.",
        "Checks if a proper tag exists.",
        "Checks if an inproper tag doesnt exist."
    });
}
