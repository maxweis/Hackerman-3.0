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

    encrypted_password_ = password_soln_;
}

void Cipher_Puzzle::cipher_setup() {
    //
}

void Cipher_Puzzle::encrypt_password() {
    encrypted_password_ = password_soln_;

    std::vector<char> encrypt_chars(num_most_common_, 65);
    static std::vector<bool> use_status(ENCRYPT_CHARS.size(), false);

    std::vector<char> most_common(num_most_common_, 65);
    std::vector<unsigned int> counts(256, 0);
    static std::vector<bool> used_common(256, false);
    
    int rand_idx = 0;
    int count_encrypt = 0;
    int count_common = 0;
    int common_idx = 0;

    for (char c: encrypted_password_) {
        counts[c]++;
    }

    while (count_common != num_most_common_) {
        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] > most_common(count_common) && used_common[i] == false) {
                most_common(count_common) = i;
                common_idx = i;
            } 
        }

        used_common[common_idx] = true;
        count_common++;
    }

    while (count_encrypt != num_most_common_) {
        rand_idx = random_int(0, ENCRYPT_CHARS.size() - 1);

        if (use_status[rand_idx] == false) {
            encrypt_chars[count_encrypt] = ENCRYPT_CHARS[rand_idx];
            use_status[rand_idx] = true;
            count_encrypt++;
        }
    }

    for (int i = 0; i < num_most_common_; i++) {
        this->replaceChar(encrypted_password_, most_common[i], encrypt_chars[i]);
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