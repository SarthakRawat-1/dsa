// Problem Statement :- https://leetcode.com/problems/count-mentions-per-user/description/

// We will do just what is said in the question.
// We will first sort the array on the basis of timestamp. For the same timestamp, offline events should come first.
// We will then handle the specific message. For this we will extract tokens i.e. mention string (which can be multiple or just one).
// We will keep track of users mentioned using a vector mentions (size = numberOfUsers).
// Let's say we were given :- {{"MESSAGE", "10",, "id1 id0"}, {"OFFLINE", "11", "0"}, {"MESSAGE", "71", "HERE"}}. 
// We extracted id1 and id0 from the string. First token is id1, so we will use another vector to track offline time for this user. If id1 is mentioned, extract the 1, and use that as index in vector (in metions vector and increase that index value by 1). 
// If the mention string is "HERE", then we will iterate the vector to track offline users (we also have to make sure that if a user goes offline at t, he/she will be back online at t + 60). The one who are online, their mention count will be increased by 1.
// "OFFLINE" events are just there to keep track of offline users and the time they went offline.

#include <bits/stdc++.h>
using namespace std;

vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    // Initialize a vector to track the total mentions for each user (index = user ID)
    vector<int> mentions(numberOfUsers, 0);
    // Track when each user will come back online (values are timestamps)
    vector<int> offline_until(numberOfUsers, 0); // 0 means online

    // Sort events by timestamp and priority (OFFLINE first at same timestamp)
    sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
        // Parse timestamps from strings to integers
        int timeA = stoi(a[1]);
        int timeB = stoi(b[1]);
        
        // Primary sort key: timestamp (ascending order)
        if (timeA != timeB) {
            return timeA < timeB; // Earlier events come first
        } else {
            // Secondary sort key: prioritize OFFLINE events over MESSAGE at same timestamp
            bool aIsOffline = (a[0] == "OFFLINE");
            bool bIsOffline = (b[0] == "OFFLINE");
            // Return true if 'a' is OFFLINE and 'b' is not (ensures OFFLINE comes first)
            return aIsOffline > bIsOffline; 
        }
    });

    // Process each event in the sorted order
    for (const auto& event : events) {
        string eventType = event[0]; // "OFFLINE" or "MESSAGE"
        int timestamp = stoi(event[1]); // Convert timestamp string to integer
        string data = event[2]; // Data payload (user ID or mention string)

        if (eventType == "OFFLINE") {
            // Handle OFFLINE event: mark user as offline until timestamp + 60
            int userID = stoi(data); // Extract user ID from data string
            offline_until[userID] = timestamp + 60; // Update offline time
        } else {
            // Handle MESSAGE event: split mention string into tokens (e.g., "id0 HERE")
            vector<string> tokens; // Stores individual tokens like "id0", "HERE", etc.
            string currentToken; // Temporary buffer to build tokens

            // Loop through each character in the data string
            for (char c : data) {
                if (c == ' ') {
                    // Space indicates end of current token
                    if (!currentToken.empty()) {
                        tokens.push_back(currentToken); // Save the token
                        currentToken.clear(); // Reset buffer for next token
                    }
                } else {
                    currentToken += c; // Append character to current token
                }
            }
            // Add the last token if not empty (data might not end with a space)
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
            }

            // Process each token in the parsed tokens list
            for (const string& token : tokens) {
                if (token == "ALL") {
                    // Case 1: Mention ALL users (online and offline)
                    for (int u = 0; u < numberOfUsers; ++u) {
                        mentions[u]++; // Increment count for every user
                    }
                } else if (token == "HERE") {
                    // Case 2: Mention only online users (timestamp >= offline_until)
                    for (int u = 0; u < numberOfUsers; ++u) {
                        // Check if user is online at this event's timestamp
                        if (timestamp >= offline_until[u]) {
                            mentions[u]++; // Increment if online
                        }
                    }
                } else if (token.substr(0, 2) == "id") {
                    // Case 3: Mention a specific user (e.g., "id0")
                    // Extract user ID from substring starting after "id"
                    int userID = stoi(token.substr(2)); // "id123" → 123
                    mentions[userID]++; // Increment the user's mention count
                }
            }
        }
    }

    // Return the final mention counts for all users
    return mentions;
}

int main() {
    int numberOfUsers = 3; // Number of users in the system
    vector<vector<string>> events = {{"MESSAGE", "10", "id1 id0"}, {"OFFLINE", "11", "0"}, {"MESSAGE", "71", "HERE"}};
    vector<int> mentionCounts = countMentions(numberOfUsers, events);
    for (int i = 0; i < numberOfUsers; ++i) {
        cout << "User " << i << " received " << mentionCounts[i] << " mentions\n";
    }
    return 0;
}