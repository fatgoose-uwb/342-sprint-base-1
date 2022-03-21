/*
 * DO NOT TOUCH THIS FILE
 */

#include <string>
#include <vector>

class Follower {
public:
    std::string name;
    int age;

    Follower(const std::string &name, int age);

    Follower(const Follower &another_follower) {
        this->name = another_follower.name;
        this->age = another_follower.age;
    }

    bool operator==(const Follower &rhs) const {
        return name == rhs.name &&
               age == rhs.age;
    }

    bool operator!=(const Follower &rhs) const {
        return !(rhs == *this);
    }
};

class Influencer {
public:
    std::string name;
    std::vector<Follower> followers;

    Influencer(const std::string &name, const std::vector<Follower> &followers);

    bool operator==(const Influencer &rhs) const {
        return name == rhs.name &&
               followers == rhs.followers;
    }

    bool operator!=(const Influencer &rhs) const {
        return !(rhs == *this);
    }

    Influencer(const Influencer &another_influencer) {
        this->name = another_influencer.name;
        this->followers = another_influencer.followers;
    }
};

class CustomerFinder {
public:
    static std::vector<Follower> find_customer(const std::vector<Influencer> &influencers);
};