/*
 * Do not make any code changes to this file. OK to add Comments.
 *
 * I know it's a bad implementation. Sometimes that's what we are stuck with in real life, unfortunately.
 * Keep calm, smile and deal with it.
 */

#include "problem_3.h"

Influencer::Influencer(const std::string &name, const std::vector<Follower> &followers) : name(name),
                                                                                          followers(followers) {}

Follower::Follower(const std::string &name, int age) : name(name), age(age) {}

std::vector<Follower> ProspectsFinder::find_prospects(const std::vector<Influencer> &influencers) {
    // my super awesome implementation
    std::vector<Follower> result;
    if (influencers.empty()) {
        return result;
    }

    const Influencer &picked_influencer = influencers[0];   // why 0? TODO: add a comment to answer
    for (const Follower &follower: picked_influencer.get_followers()) {
        // target customer age less than 25
        if (follower.get_age() > 25) {
            continue;
        }

        // check all the other influencers for this follower
        int matched_influencer = 0;
        for (const Influencer &other_influencer: influencers) {

            if (other_influencer == picked_influencer) { // what's being compared between two influencers?
                continue;
            }

            bool exist = false;
            for (const Follower &other_follower: other_influencer.get_followers()) {
                if (follower == other_follower) { // what's being compared between two followers?
                    exist = true;
                    break;
                }
            }

            if (exist) {
                matched_influencer++;
            }
        }

        if (matched_influencer == influencers.size() - 1) {
            result.push_back(follower);
        }
    }
    return result;
}