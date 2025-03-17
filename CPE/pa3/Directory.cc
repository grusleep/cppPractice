#include "Directory.h"

#include <iomanip>
#include <sstream>

//DO NOT MODIFY THIS START
Entry* Directory::clone() const
{
    return new Directory(*this);
}
//DO NOT MODIFY THIS END

//Implement constructor, destructor, member functions of the Directory class.
Directory::Directory(const std::string& name)
         : name_(name), count_(0) {}

Directory::Directory(const Directory& o)
{
    name_ = o.name();
    count_ = o.count();
    for (size_t i = 0; i < count_; i++)
    {
        entries_[i] = o.entries_[i]->clone();
    }
}

Directory::~Directory()
{
    for (size_t i = 0; i < count_; i++)
        delete entries_[i];
}

const std::string& Directory::name() const
{
    return name_;
}

void Directory::print(std::ostream& os, size_t indent) const
{
    os << std::string(indent, ' ') << "* " << name_ << std::endl;
    for (size_t i = 0; i < count_; i++)
    {
        entries_[i]->print(os, indent + print_indent_);
    }
}

std::string Directory::content() const
{
    std::ostringstream oss;
    for (size_t i = 0; i < count_; i++) {
        oss << entries_[i]->name() << std::endl;
    }
    return oss.str();
}

size_t Directory::count() const
{
    return count_;
}

Entry* Directory::find(const std::string& name)
{
    for (size_t i = 0; i < count_; i++) {
        if (entries_[i]->name() == name) {
            return entries_[i];
        }
    }
    return nullptr;
}

bool Directory::add(Entry* entry)
{
    if (count_ >= maxcount_) return false;
    for (size_t i = 0; i < count_; i++)
    {
        if (entries_[i]->name() == entry->name()) return false;
    }
    entries_[count_++] = entry->clone();
    return true;
}

Entry* Directory::remove(const std::string& name)
{
    for (size_t i = 0; i < count_; i++)
    {
        if (entries_[i]->name() == name)
        {
            Entry* removed = entries_[i];
            for (size_t j = i; j < count_ - 1; j++)
            {
                entries_[j] = entries_[j + 1];
            }
            entries_[--count_] = nullptr;
            return removed;
        }
    }
    return nullptr;
}

//...
