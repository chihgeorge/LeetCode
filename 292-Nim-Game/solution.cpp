class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
        
        //  Thoughts:
        //  Since the one who removes the last stone will be the winner, 
        //  we have to make sure we can remove 1-3 stones in the last turn.
        //  As we always go first, if the number of stones can be divided by 4, 
        //  whatever any number of stones we pick, we will always lose the game.
        //  (We pick 1,2 or 3, and the friends can pick 3, 2 or 1)
        //  If the number of stones can not be divided by 4, we will always win.
    }
};