#include <iostream>
#include <filesystem>
#include <regex>
#include <algorithm>

using namespace std;

int main() {
    string dirName;
    getline(cin, dirName);

    transform(dirName.begin(), dirName.end(), dirName.begin(), ::tolower);

    regex dotPattern("\\.");
    string dirNameNoSpace = regex_replace(dirName, dotPattern, "");

    regex spacePattern("\\s");
    dirNameNoSpace = regex_replace(dirNameNoSpace, spacePattern, "_");

    int index = dirNameNoSpace.find("_");
    string fileName = dirNameNoSpace.substr(0, index);

    namespace fs = filesystem;
    fs::create_directories("./" + dirNameNoSpace + "/" + fileName + ".cpp");

    return 0;
}