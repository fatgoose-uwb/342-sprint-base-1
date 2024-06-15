/*
 * Do not make any changes to this file
 */

#include <string>
#include <vector>

class Follower {
private:
    std::string name;
    int age;

public:
    Follower(const std::string &name, int age); // Why & is used here and why const? what happens & is not used?

    Follower(const Follower &another_follower) {
        this->name = another_follower.name; // What is "this"?
        this->age = another_follower.age;
    }

    bool operator==(const Follower &rhs) const {    // Remember the "equals" function in Java?
        return name == rhs.name && age == rhs.age;
    }

    bool operator!=(const Follower &rhs) const {
        return !(rhs == *this); // What is "*this"?
    }

    int get_age() const {
        return age;
    }
};

/*
 * "Two classes in the same file. Huh. Take that, Java."
 */
class Influencer {
    std::string name;
    std::vector<Follower> followers; // What is std::vector? Is it just a fancy array like ArrayList in Java?

public:
    Influencer(const std::string &name, const std::vector<Follower> &followers);

    bool operator==(const Influencer &rhs) const {
        return name == rhs.name &&  // why is rhs.name used here instead of rhs->name?
               followers == rhs.followers;
    }

    bool operator!=(const Influencer &rhs) const {
        return !(rhs == *this); // This condition is great for printing on a shirt
    }

    Influencer(const Influencer &another_influencer) {
        this->name = another_influencer.name;
        this->followers = another_influencer.followers; // What happens with this "="? Is this making a copy of all the follower objects?
    }

    const std::vector<Follower> &get_followers() const {    // what does the two "const" do?
        return followers;
    }
};

class ProspectsFinder {
public:
    static std::vector<Follower> find_prospects(const std::vector<Influencer> &influencers); // What does "static" do?
};