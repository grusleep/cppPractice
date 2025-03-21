#include "File.h"

#include <iomanip>

//DO NOT MODIFY START
File::~File() = default;

Entry* File::clone() const
{
    return new File(*this);
}
//DO NOT MODIFY END

//Implement constructor, member functions in File class
//write your code here
File::File(const std::string& name, const std::string& content)
    : name_(name), text_(content) {}

File::File(const File& o)
{
    name_ = o.name();
    text_ = o.content();
}

const std::string& File::name() const
{
    return name_;
}

void File::print(std::ostream& os, size_t indent) const
{
    os << std::string(indent-1, ' ') << "* " << name_ << std::endl;
}

std::string File::content() const
{
    return text_;
}

std::string File::content(const std::string& text)
{
    text_ = text;
    return "Content updated!\n";
}

//...
