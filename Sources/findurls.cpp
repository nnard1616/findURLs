#include "../Headers/findurls.hpp"

bool is_url_char(char sc)
{
    string acceptable =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/"
        "?#[]@!$&'()*+,;=`.";
    if (acceptable.find(sc) != string::npos)
        return true;
    return false;
}

vector<string> find_URLs(string fileName)
{
    std::fstream inFile(fileName);
    string url;           // temporary storage of url
    vector<string> urls;  // store urls, return at end

    std::istream_iterator<char> eos;  // end of stream iterator
    std::istream_iterator<char> iit(inFile);

    // invariant: vector urls contains strings of all urls found in html file.
    while (iit != eos)
    {
        if (*iit == 'h')
        {
            iit++;
            if (*iit == 't')
            {
                iit++;
                if (*iit == 't')
                {
                    iit++;
                    if (*iit == 'p')
                    {
                        iit++;
                        if (*iit == 's')
                        {
                            iit++;
                            if (*iit == ':')
                            {
                                iit++;
                                if (*iit == '/')
                                {
                                    iit++;
                                    if (*iit == '/')
                                    {
                                        iit++;
                                        url = "https://";
                                        while (is_url_char(*iit))
                                        {
                                            url.push_back(*iit);
                                            iit++;
                                        }
                                        urls.push_back(url);
                                    }
                                }
                            }
                        }
                        if (*iit == ':')
                        {
                            iit++;
                            if (*iit == '/')
                            {
                                iit++;
                                if (*iit == '/')
                                {
                                    iit++;
                                    url = "http://";
                                    while (is_url_char(*iit))
                                    {
                                        url.push_back(*iit);
                                        iit++;
                                    }
                                    urls.push_back(url);
                                }
                            }
                        }
                    }
                }
            }
        }
        else
            iit++;
    }
    return urls;
}
