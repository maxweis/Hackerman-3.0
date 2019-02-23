#pragma once

#include "maths.h"
#include <string>
#include <vector>

const std::vector<std::string> PASSWORD_STRS = {"save", "gaping", "leap", "please", "dusty",
                                                "attract", "hospital", "quiet", "comfort", "probable", 
                                                "complex", "dashing", "restrain", "society", "functional",
                                                "sterilize", "regard", "near", "copper", "clocks",
                                                "snail", "scan", "ethereal", "brothers", "permit",
                                                "hinder", "steam", "free", "five", "stick",
                                                "tramp", "plough", "sob", "increase", "religion",
                                                "grow", "equal", "glass", "crackle", "change",
                                                "willing", "spotless", "worship", "seed", "important",
                                                "preserve", "gold", "merciful", "material", "push",
                                                "see", "impose", "nasty", "idiotic", "dip",
                                                "copper", "thing", "crime", "ray", "cow",
                                                "paint", "wool", "climb", "giant", "odd"};

const std::vector<char> ENCRYPT_CHARS = {};

class Cipher_Puzzle {
  public:
    Cipher_Puzzle() : length_(0), num_most_common_(0), password_soln_(""), encrypted_password_("");
    Cipher_Puzzle(int length, int num_most_commmon);

    void cipher_setup();
    
    void generate_password();
    void encrypt_password();

    bool verify_soln(std::string answer);

  private:
    int length_;
    int num_most_common_;
    std::string password_soln_;
    std::string encrypted_password_;

    std::string replaceChar(std::string str, char old_ch, char new_ch);
};