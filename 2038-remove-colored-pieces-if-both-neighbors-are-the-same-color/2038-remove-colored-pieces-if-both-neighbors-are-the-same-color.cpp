class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice_plays = 0, bob_plays = 0, count = 0;
        
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i - 1]) {
                count++;
            } else {
                if (colors[i - 1] == 'A') {
                    alice_plays += max(0, count - 1);
                } else {
                    bob_plays += max(0, count - 1);
                }
                count = 0;
            }
        }

        if (colors.back() == 'A') {
            alice_plays += max(0, count - 1);
        } else {
            bob_plays += max(0, count - 1);
        }
        
        return alice_plays > bob_plays;
    }
};