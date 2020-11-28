#include "LFont.hxx"
#include "ttfUtils.hxx"

LFont::~LFont()
{
    this->free();
}

void LFont::free()
{
    if (this->font != nullptr)
    {
        cleanup(this->font);
        this->font = nullptr;
    }
}

bool LFont::loadFromFile(const std::string &filename, int fontSize)
{
    this->free();
    this->font = loadFont(filename, fontSize);
    return this->font != nullptr;
}