#include "cipher.h"
#include "maths.h"
#include <string>

Cipher_Puzzle::Cipher_Puzzle(int length, int num_most_commmon) {
    length_ = length;
    num_most_common_ = num_most_common;
    std::string password_soln_ = "";
    std::string encrypted_password_ = "";
}

void Cipher_Puzzle::generate_password() {
    int rand_idx = 0;

    for (int i = 0; i < length_; i++) {
        rand_idx = random_int(0, PASSWORD_STRS.size() - 1);

        if (i == 0) {
            password_soln_ += PASSWORD_STRS[rand_idx];
        }
        else {
            password_soln_ += " " + PASSWORD_STRS[rand_idx];
        }
    }
}

void Cipher_Puzzle::cipher_setup() {
    //
}

void Cipher_Puzzle::encrypt_password() {
    unsigned int char_counts[256] = {0};
    std::vector<char> encrypt_chars;

    for (size_t i = 0; i < password_soln_.size(); i++) {
        char_counts[(unsigned char)password_soln_[i]]++;
    }

    for () {

    }
}

bool Cipher_Puzzle::verify_soln(std::string answer) {
    bool solved = false;

    if (answer == password_soln_) {
        solved = true;
    }

    return solved;
}

std::string Cipher_Puzzle::replaceChar(std::string str, char old_ch, char new_ch) {
    for (char &c: str) {
        if (c == old_ch) {
            c = new_ch;
        }
    }
}