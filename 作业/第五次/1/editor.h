#pragma once

#include <vector>
#include <string>
#include <list>

class TextEditor {
private:
    using Position = std::pair<int, int>;
    std::vector<std::string> data; // 数据区，亦可采用其他数据结构
    std::vector<std::string> clipboard; // 剪贴板，亦可采用其他数据结构
    Position p;
    bool isSelect;
public:
    TextEditor();
    void moveCursor(Position dest);
    void select(Position beg, Position end);
    void write(const std::string& str);
    void newline();
    void del();
    void copy();
    void paste();
    void screenShot();
};

TextEditor::TextEditor()
{
    this->p = std::make_pair(0,0);
    this->isSelect = false;
}
void TextEditor::moveCursor(Position dest)
{
    if(this->isSelect)
        this->isSelect = false;
    this->p = dest;
}
void TextEditor::select(Position beg, Position end)
{

}
























