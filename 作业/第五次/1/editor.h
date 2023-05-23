#pragma once
#include<iostream>
#include<vector>
#include<utility>


class TextEditor {
private:
    using Position = std::pair<int, int>;
    std::vector<std::string> data; 
    std::vector<std::string> clipboard; 
    Position cursor;
    Position selectionStart;
    Position selectionEnd;
    bool isSelectionActive = false;

public:
    TextEditor() {
        data.push_back("");
        cursor = {0, 0};
    }

    void moveCursor(Position dest) {
        isSelectionActive = false;
        cursor = dest;
    }

    void select(Position beg, Position end) {
        selectionStart = beg;
        selectionEnd = end;
        isSelectionActive = true;
    }

    void write(const std::string& str) {
        if (isSelectionActive) {
            // replace selection with str
            std::string &line = data[selectionStart.first];
            line.replace(selectionStart.second, selectionEnd.second - selectionStart.second, str);
            isSelectionActive = false;
            cursor = {selectionStart.first, selectionStart.second + str.size()};
        } else {
            data[cursor.first].insert(cursor.second, str);
            cursor.second += str.size();
        }
    }

    void newline() {
        if (isSelectionActive) {
            // delete selection first
            std::string &line = data[selectionStart.first];
            line.erase(selectionStart.second, selectionEnd.second - selectionStart.second);
            isSelectionActive = false;
        }

        std::string old_line = data[cursor.first];
        std::string new_line = old_line.substr(cursor.second);
        old_line = old_line.substr(0, cursor.second);

        data[cursor.first] = old_line;
        data.insert(data.begin() + cursor.first + 1, new_line);

        cursor = {cursor.first + 1, 0};
    }

    void del() {
        if (isSelectionActive) {
            // delete selection
            std::string &line = data[selectionStart.first];
            line.erase(selectionStart.second, selectionEnd.second - selectionStart.second);
            isSelectionActive = false;
            cursor = selectionStart;
        } else {
            if (cursor.second > 0) {
                data[cursor.first].erase(cursor.second - 1, 1);
                cursor.second--;
            } else if (cursor.first > 0) {
                int end_of_prev_line = data[cursor.first - 1].size();
                data[cursor.first - 1] += data[cursor.first];
                data.erase(data.begin() + cursor.first);
                cursor = {cursor.first - 1, end_of_prev_line};
            }
        }
    }

    void copy() {
        if (isSelectionActive) {
            // copy selection to clipboard
            clipboard.clear();
            for (int i = selectionStart.first; i <= selectionEnd.first; ++i) {
                if (i == selectionStart.first && i == selectionEnd.first) {
                    clipboard.push_back(data[i].substr(selectionStart.second, selectionEnd.second - selectionStart.second));
                } else if (i == selectionStart.first) {
                    clipboard.push_back(data[i].substr(selectionStart.second));
                } else if (i == selectionEnd.first) {
                    clipboard.push_back(data[i].substr(0, selectionEnd.second));
                } else {
                    clipboard.push_back(data[i]);
                }
            }
        }
    }

    void paste() {
        if (isSelectionActive) {
            // replace selection with clipboard content
            del();
        }
        
        // insert clipboard content at cursor
        for (const auto &str : clipboard) {
            write(str);
            newline();
        }
    }

    void screenShot() {
        // print the content of data with '*' indicating the cursor or selection
        for (int i = 0; i < data.size(); ++i) {
            if (i == cursor.first) {
                std::string line = data[i];
                line.insert(cursor.second, "*");
                std::cout << line << std::endl;
            } else {
                std::cout << data[i] << std::endl;
            }
        }
    }
};
