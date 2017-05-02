#include "Headers/findurls.hpp"

int main()
{
    vector<string> urls = find_URLs("../redditPage.html");

    std::cout << urls.size() << std::endl;
    return 0;
}
