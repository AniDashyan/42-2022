#ifndef CGI_HPP
#define CGI_HPP

class CGI {
    public:
        CGI();
        CGI(const CGI& other);
        CGI& operator=(const CGI& other);
        ~CGI();
};

#endif